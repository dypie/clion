#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <thread>
#include <ctime>
#include <time.h>



// ее надо отдельно накатывать
const int LIMIT = 8;

template<typename T>
struct desc {
    bool operator ()(T a, T b) {
        return a > b;
    }
};

template<typename T>
struct asc {
    bool operator ()(T a, T b) {
        return a < b;
    }
};

template<typename T, typename Compare>
T partition(T *first, T *last, Compare comp);

template<typename T, typename Compare>
void baseQsort(T *first, T *last, Compare comp) {
    int border = partition(first, last, comp);
    if (border - 1 > 0) {
        baseQsort(first, first + border - 1, comp);
    }
    if (border < (last - first)) {
        baseQsort(first + border, last, comp);
    }
}

template<typename T, typename Compare>
void firstOptimizedQsort(T *first, T *last, Compare comp) {
    int border = partition(first, last, comp);

    if (border <= LIMIT) {
        insertionSort(first, first + border - 1, comp);
    }
    else {
        if (border - 1 > 0) {
            firstOptimizedQsort(first, first + border - 1, comp);
        }
    }

    if ((last - first) - border <= LIMIT) {
        insertionSort(first + border, last, comp);
    }
    else {
        if (border < (last - first)) {
            firstOptimizedQsort(first + border, last, comp);
        }
    }
}

template<typename T, typename Compare>
void secondOptimizedQsort(T *first, T *last, Compare comp) {
    if (last - first <= LIMIT) {
        insertionSort(first, last,comp);
    }
    else {
        while (first < last) {
            int pivot = partition(first, last, comp);
            if ( pivot < (last - first) / 2 ) {
                secondOptimizedQsort(first, first + pivot - 1, comp);
                first = first + pivot ;
            }
            else {
                secondOptimizedQsort(first + pivot, last, comp);
                last = first + pivot - 1;
            }
        }
    }
}

template<typename T>
void alternativeSwap(T* a, T* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
T median(T a, T b, T c) {
    T _min = std::min(a, std::min(b, c));
    T _max = std::max(a, std::max(b, c));
    return (a + b + c) - _min - _max;
}

template<typename T, typename Compare>
T partition(T *first, T *last, Compare comp) {
    // find index of mid element
    int size = last - first;
    int midElement = (size / 2);
    // find real value of mid element
    T* realMidEl = first + midElement;
    // find pivot
    T pivot = median(*first, *realMidEl, *last);

    int start = 0;
    int end = last - first;

    while(start <= end) {
        while ( comp(*(first + start), pivot) ) {
            start++;
        }
        while ( comp(pivot, *(first + end)) ) {
            end--;
        }
        if (start <= end) {
            alternativeSwap((first + start), (first + end));
            start++;
            end--;
        }
    }
    return start;
}

template<typename T, typename Compare>
void insertionSort(T *first, T *last, Compare comp) {
    for (T *current = first + 1; current <= last; current++) {
        T *tempFirst = current - 1;
        while (comp(*current, *tempFirst) && tempFirst >= first) {
            alternativeSwap(current, tempFirst);
            tempFirst--;
            current--;
        }
    }
}



