#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <random>

#include "TSQueue.h"



template<typename T, template<typename> class Container>
std::ostream &operator<<(std::ostream &os, const Container<T> &data) {
    for (auto item : data) {
        os << item << " ";
    }
    return os;
}

std::vector<int> GenerateRandomVector(int NumberCount,int minimum, int maximum) {
    std::random_device rd;
    std::mt19937 gen(rd()); // these can be global and/or static, depending on how you use random elsewhere

    std::vector<int> values(NumberCount);
    std::uniform_int_distribution<> dis(minimum, maximum);
    std::generate(values.begin(), values.end(), [&](){ return dis(gen); });
    return values;
}

int main() {

    TSQueue<std::vector<int>> q;

    for (int i = 0; i < 10; ++i) {
        std::vector<int> data = GenerateRandomVector(100, 0, 900);
        q.push(data);
    }

    // Pop some data
    for (;q.size() > 0;) {
        auto item = q.pop();
         std::cout << item.value() << std::endl;
    }

    return 0;
}
