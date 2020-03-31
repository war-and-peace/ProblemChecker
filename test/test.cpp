#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <filesystem>
#include <fstream>
#include <ios>

#include "../src/checkers/IntChecker.hpp"

TEST_CASE("Int Checker is working properly", "[int_checker]") {
    std::string file_path1{"output_file_1"};
    std::string file_path2{"output_file_2"};
    std::ofstream out{file_path1, std::ios_base::out};
    out << "1";
    out.close();
    std::ofstream out2{file_path2, std::ios_base::out};
    out2 << "1";
    out.close();
    namespace fs = std::filesystem;

    REQUIRE(fs::exists(fs::path(file_path1)));
    REQUIRE(fs::is_regular_file(fs::path(file_path1)));
    REQUIRE(fs::exists(fs::path(file_path2)));
    REQUIRE(fs::is_regular_file(fs::path(file_path2)));

    SECTION("int checker run") {
        auto tester = checker::IntChecker{file_path1, file_path2};
        REQUIRE(tester.check());
    }
}
