//
// Created by abdurasul on 05.05.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch2/catch.hpp>
#include <vector>
#include "../src/checker/checkers.h"

TEST_CASE("Check trivial types", "[trivial_types_checker]") {
    REQUIRE(checkers::equal(1, 1));
    REQUIRE(!checkers::equal(1, 2));
    REQUIRE(!checkers::equal('a', 'b'));
    REQUIRE(checkers::equal('b', 'b'));
}

TEST_CASE("String and string literals", "[string]") {
    REQUIRE(checkers::equal("123", "123"));
    REQUIRE(checkers::equal("123", "123"));
    REQUIRE(!checkers::equal("123d", "123"));
    REQUIRE(checkers::equal("123", "123"));
    REQUIRE(checkers::equal(std::string("123"), "123"));
    REQUIRE(!checkers::equal(std::string("123"), "123d"));
}

TEST_CASE("Containers", "[container]") {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {1, 2, 3, 4};

    REQUIRE(checkers::equal(a, b));

    b.pop_back();
    REQUIRE(!checkers::equal(a, b));
}

TEST_CASE("Floating point", "[floating_point]") {
    REQUIRE(checkers::equal(1.2, 1.1, 0.2));
    REQUIRE(checkers::equal(1.123, 1.123, 1e-15));
    REQUIRE(!checkers::equal(3.14, 3.145, 1e-5));
}