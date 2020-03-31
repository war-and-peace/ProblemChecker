#include <iostream>
#include "checkers/IntChecker.hpp"
#include <string_view>
#include <utility>

int main(){
    std::cout << "something" << std::endl;
    auto pair = std::make_pair<int, int> (1, 2);
    auto [x, y] = pair;
    std::string_view s{"something"};
    checker::IntChecker a{"f1", "f2"};
    std::cout << "Working" << std::endl;
    return 0;
}