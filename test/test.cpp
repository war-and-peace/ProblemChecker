#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include <filesystem>
#include <fstream>
#include <ios>

#include "../src/checkers/IntChecker.hpp"

const std::string file_path1{"output_file_1"};
const std::string file_path2{"output_file_2"};

void int_checker_setting1(std::string_view content1, std::string_view content2) {
    std::ofstream out{file_path1, std::ios_base::out};
    out << content1;
    out.close();
    std::ofstream out2{file_path2, std::ios_base::out};
    out2 << content2;
    out.close();
}

void check_files_exist() {
    namespace fs = std::filesystem;
    REQUIRE(fs::exists(fs::path(file_path1)));
    REQUIRE(fs::is_regular_file(fs::path(file_path1)));
    REQUIRE(fs::exists(fs::path(file_path2)));
    REQUIRE(fs::is_regular_file(fs::path(file_path2)));
}

TEST_CASE("Int Checker on equal values", "[int_checker]") {
    int_checker_setting1("1", "1");

    check_files_exist();

    auto tester = checker::IntChecker{file_path1, file_path2};
    REQUIRE(tester.check() == true);
}

TEST_CASE("Int Checker on non-equal values", "[int_checker]") {
    int_checker_setting1("1", "0");

    check_files_exist();

    auto tester = checker::IntChecker(file_path1, file_path2);
    REQUIRE(tester.check() == false);
}

TEST_CASE("Int Checker on non-existing files", "[int_checker]") {
    bool exception_thrown_flag{false};
    try {
        auto tester = checker::IntChecker{"name1", "name2"};  // non-existing file names
        auto result = tester.check();
    } catch (checker::FileErrorException& e) {
        exception_thrown_flag = true;  // Should throw FileErrorException
    } catch (...) {
        REQUIRE(false);  // Fail if any other exception
    }
    REQUIRE(exception_thrown_flag);  // Fail if no exception
}

TEST_CASE("Int Checker on invalid values", "[int_checker]") {
    int_checker_setting1("invalid", "invalid");  // non-integer values are given

    check_files_exist();

    auto tester = checker::IntChecker(file_path1, file_path2);
    REQUIRE(tester.check() == false);
}