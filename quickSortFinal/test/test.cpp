#include "gtest/gtest.h"
#include <C:\Users\Dmitry\CLionProjects\quickSortFinal\main.h>
#include <fstream>
#include <gtest/gtest.h>
#include <vector>
#include <string>

class TestSerialization : public ::testing::Test {
public:
    TestSerialization() { /* init protected members here */ }
    ~TestSerialization() { /* free protected members here */ }
    void SetUp() { /* called before every test */ }
    void TearDown() { /* called after every test */ }
};

std::vector<int> test_vector_asc{ 2, 3, 4, 7, 8 };
std::vector<int> test_vector_desc{ 8, 7, 4, 3, 2 };

std::vector<int> test_vector_one_element{ 2 };
std::vector<int> test_vector_two_element{ 2, 3 };

std::vector<float> float_test_vector_asc{ 2., 3., 4., 7., 8. };
std::vector<float> float_test_vector_desc{ 8., 7., 4., 3., 2. };

std::vector<char> char_test_vector_asc{ 'a', 'b', 'c', 'd', 'e'};
std::vector<char> char_test_vector_desc{ 'e', 'd', 'c', 'b', 'a'};



TEST_F(TestSerialization, SORT_DESC_INT) {

    std::vector<int> test_vector{ 3, 4, 2, 7, 8 };
    std::vector<int> test_vector1(test_vector);
    std::vector<int> test_vector2(test_vector);
    std::vector<int> test_vector3(test_vector);

    secondOptimizedQsort(&test_vector[0], &test_vector[test_vector.size() - 1], desc<int>());
    firstOptimizedQsort(&test_vector1[0], &test_vector1[test_vector1.size() - 1], desc<int>());
    baseQsort(&test_vector2[0], &test_vector2[test_vector2.size() - 1], desc<int>());
    insertionSort(&test_vector3[0], &test_vector3[test_vector3.size() - 1], desc<int>());

    ASSERT_EQ(test_vector, test_vector_desc);
    ASSERT_EQ(test_vector1, test_vector_desc);
    ASSERT_EQ(test_vector2, test_vector_desc);
    ASSERT_EQ(test_vector3, test_vector_desc);
}

TEST_F(TestSerialization, SORT_ASC_INT) {

    std::vector<int> test_vector{ 3, 4, 2, 7, 8 };
    std::vector<int> test_vector1(test_vector);
    std::vector<int> test_vector2(test_vector);
    std::vector<int> test_vector3(test_vector);

    secondOptimizedQsort(&test_vector[0], &test_vector[test_vector.size() - 1], asc<int>());
    firstOptimizedQsort(&test_vector1[0], &test_vector1[test_vector1.size() - 1], asc<int>());
    baseQsort(&test_vector2[0], &test_vector2[test_vector2.size() - 1], asc<int>());
    insertionSort(&test_vector3[0], &test_vector3[test_vector3.size() - 1], asc<int>());

    ASSERT_EQ(test_vector, test_vector_asc);
    ASSERT_EQ(test_vector1, test_vector_asc);
    ASSERT_EQ(test_vector2, test_vector_asc);
    ASSERT_EQ(test_vector3, test_vector_asc);
}

TEST_F(TestSerialization, SORT_DESC_FLOAT) {

    std::vector<float> test_vector{ 3., 4., 2., 7., 8. };
    std::vector<float> test_vector1(test_vector);
    std::vector<float> test_vector2(test_vector);
    std::vector<float> test_vector3(test_vector);

    secondOptimizedQsort(&test_vector[0], &test_vector[test_vector.size() - 1], desc<float>());
    firstOptimizedQsort(&test_vector1[0], &test_vector1[test_vector1.size() - 1], desc<float>());
    baseQsort(&test_vector2[0], &test_vector2[test_vector2.size() - 1], desc<float>());
    insertionSort(&test_vector3[0], &test_vector3[test_vector3.size() - 1], desc<float>());

    ASSERT_EQ(test_vector, float_test_vector_desc);
    ASSERT_EQ(test_vector1, float_test_vector_desc);
    ASSERT_EQ(test_vector2, float_test_vector_desc);
    ASSERT_EQ(test_vector3, float_test_vector_desc);

}

TEST_F(TestSerialization, SORT_ASC_FLOAT) {

    std::vector<float> test_vector{ 3., 4., 2., 7., 8. };
    std::vector<float> test_vector1(test_vector);
    std::vector<float> test_vector2(test_vector);
    std::vector<float> test_vector3(test_vector);

    secondOptimizedQsort(&test_vector[0], &test_vector[test_vector.size() - 1], asc<float>());
    firstOptimizedQsort(&test_vector1[0], &test_vector1[test_vector1.size() - 1], asc<float>());
    baseQsort(&test_vector2[0], &test_vector2[test_vector2.size() - 1], asc<float>());
    insertionSort(&test_vector3[0], &test_vector3[test_vector3.size() - 1], asc<float>());

    ASSERT_EQ(test_vector, float_test_vector_asc);
    ASSERT_EQ(test_vector1, float_test_vector_asc);
    ASSERT_EQ(test_vector2, float_test_vector_asc);
    ASSERT_EQ(test_vector3, float_test_vector_asc);
}

TEST_F(TestSerialization, SORT_DESC_CHAR) {

    std::vector<char> test_vector{ 'a', 'c', 'e', 'd', 'b' };
    std::vector<char> test_vector1(test_vector);
    std::vector<char> test_vector2(test_vector);
    std::vector<char> test_vector3(test_vector);

    secondOptimizedQsort(&test_vector[0], &test_vector[test_vector.size() - 1], desc<char>());
    firstOptimizedQsort(&test_vector1[0], &test_vector1[test_vector1.size() - 1], desc<char>());
    baseQsort(&test_vector2[0], &test_vector2[test_vector2.size() - 1], desc<char>());
    insertionSort(&test_vector3[0], &test_vector3[test_vector3.size() - 1], desc<char>());

    ASSERT_EQ(test_vector, char_test_vector_desc);
    ASSERT_EQ(test_vector1, char_test_vector_desc);
    ASSERT_EQ(test_vector2, char_test_vector_desc);
    ASSERT_EQ(test_vector3, char_test_vector_desc);
}

TEST_F(TestSerialization, SORT_ASC_CHAR) {

    std::vector<char> test_vector{ 'a', 'c', 'e', 'd', 'b' };
    std::vector<char> test_vector1(test_vector);
    std::vector<char> test_vector2(test_vector);
    std::vector<char> test_vector3(test_vector);

    secondOptimizedQsort(&test_vector[0], &test_vector[test_vector.size() - 1], asc<char>());
    firstOptimizedQsort(&test_vector1[0], &test_vector1[test_vector1.size() - 1], asc<char>());
    baseQsort(&test_vector2[0], &test_vector2[test_vector2.size() - 1], asc<char>());
    insertionSort(&test_vector3[0], &test_vector3[test_vector3.size() - 1], asc<char>());

    ASSERT_EQ(test_vector, char_test_vector_asc);
    ASSERT_EQ(test_vector1, char_test_vector_asc);
    ASSERT_EQ(test_vector2, char_test_vector_asc);
    ASSERT_EQ(test_vector3, char_test_vector_asc);
}

TEST_F(TestSerialization, ONE_ELEMENT) {

    std::vector<int> test_vector{ 2 };
    std::vector<int> test_vector1(test_vector);
    std::vector<int> test_vector2(test_vector);
    std::vector<int> test_vector3(test_vector);

    secondOptimizedQsort(&test_vector[0], &test_vector[test_vector.size() - 1], desc<int>());
    firstOptimizedQsort(&test_vector1[0], &test_vector1[test_vector1.size() - 1], desc<int>());
    baseQsort(&test_vector2[0], &test_vector2[test_vector2.size() - 1], desc<int>());
    insertionSort(&test_vector3[0], &test_vector3[test_vector3.size() - 1], desc<int>());

    ASSERT_EQ(test_vector, test_vector_one_element);
    ASSERT_EQ(test_vector1, test_vector_one_element);
    ASSERT_EQ(test_vector2, test_vector_one_element);
    ASSERT_EQ(test_vector3, test_vector_one_element);
}

TEST_F(TestSerialization, TWO_ELEMENT) {

    std::vector<int> test_vector{ 2, 3 };
    std::vector<int> test_vector1(test_vector);
    std::vector<int> test_vector2(test_vector);
    std::vector<int> test_vector3(test_vector);

    secondOptimizedQsort(&test_vector[0], &test_vector[test_vector.size() - 1], asc<int>());
    firstOptimizedQsort(&test_vector1[0], &test_vector1[test_vector1.size() - 1], asc<int>());
    baseQsort(&test_vector2[0], &test_vector2[test_vector2.size() - 1], asc<int>());
    insertionSort(&test_vector3[0], &test_vector3[test_vector3.size() - 1], asc<int>());

    ASSERT_EQ(test_vector, test_vector_two_element);
    ASSERT_EQ(test_vector1, test_vector_two_element);
    ASSERT_EQ(test_vector2, test_vector_two_element);
    ASSERT_EQ(test_vector3, test_vector_two_element);
}

TEST_F(TestSerialization, LONG_ARRAY) {

    auto f = []() -> int { return 1 + rand() % 10; };
    const int ARRAY_LEN = 100000;

    std::vector<int> vec(ARRAY_LEN);
    std::vector<int> vecToFunc;

    std::generate(vec.begin(), vec.end(), f);
    for (int value : vec) {
        vecToFunc.push_back(value);
    }

    std::sort(vec.begin(), vec.end());

    secondOptimizedQsort(&vecToFunc[0], &vecToFunc[vecToFunc.size() - 1], asc<int>());

    ASSERT_EQ(vec, vecToFunc);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


