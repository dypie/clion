#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>
#include <regex>
#include <fstream>

std::random_device rd;

//1d6, 2d6, 3d6, 1d10, 2d10, 3d10

struct Dice {
    int numberOfDices;
    int numberOfEdges;
    int modifier;

    Dice(int numberOfDices, int numberOfEdges, int modifier) {
        this->numberOfDices = numberOfDices;
        this->numberOfEdges = numberOfEdges;
        this->modifier = modifier;
    }

    void printStruct () {
        std::cout << this->numberOfDices << std::endl
        << this->numberOfEdges << std::endl
        << this->modifier << std::endl;
    }
};

Dice parseString(std::string& str) {
    std::regex r(R"(\dd_\d\+\d)");
    std::regex r1(R"(\dd_\d)");

    std::smatch m;

    if (std::regex_match(str, m, r1)) {
        Dice res {(int)str[3] - 48,
                  (int)str[0] - 48,
                  (int)str[str.length() - 1] - 48};
        return res;

    } else {
        if (std::regex_match(str, m, r)) {
            Dice res {(int)str[3] - 48,
                      (int)str[0] - 48,
                      0};
            return res;
        }
        else {std::cout << "ERROR" << std::endl;}
    }
}


std::string parseStruct(Dice& dice) {
    std::string conf;
    conf.append(std::to_string(dice.numberOfDices)).append("d").append(std::to_string(dice.numberOfEdges));
    if(dice.modifier > 0) {
        conf.append("+").append(std::to_string(dice.modifier));
    }
    return conf;
}

int ThrowDice(Dice& dice) {

    std::mt19937 generator(rd());
    std::uniform_int_distribution<>uniformDistr(1, dice.numberOfEdges);

    int res = 0;

    for(int i = 0; i < dice.numberOfDices; i++) {
        res += uniformDistr(generator) + dice.modifier;
    }
    return res;
}

int ThrowDices(const std::vector<Dice>& dices) {

    int res = 0;

    for(Dice dice : dices) {
        res += ThrowDice(dice);
    }

    return res;
}

int main() {

    Dice d6_1 {1, 6, 0};
    Dice d6_2 {2, 6, 0};
    Dice d6_3 {3, 6, 0};
    Dice d6_4 {4, 6, 0};
    Dice d10_1 {1, 10, 0};
    Dice d10_2 {2, 10, 0};
    Dice d10_3 {3, 10, 0};

    std::vector<int> summa;
    std::vector<float> mean;
    std::vector<Dice> dices = {d6_1, d6_2, d6_3, d6_4, d10_1, d10_2, d10_3};

    std::ofstream data ("data.csv");

    for(int i = 0; i < 30000; i++) {
        std::string toCsv;
        for(Dice dice : dices) {
            int res;
            res = ThrowDice(dice);
            toCsv.append((std::to_string(res)) + ",");
        }
        data << toCsv;
        data << std::endl;
    }

    data.close();

    std::string diceTest = "2d_6+1";

    std::cout << parseStruct(d10_3);

    Dice res = parseString(diceTest);
    res.printStruct();

}
