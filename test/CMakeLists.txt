find_package(Catch2 REQUIRED)
include_directories(../src/checker)
add_executable(Test test_checkers.cpp)
target_link_libraries(Test Catch2::Catch2)
#target_link_libraries(Test src/checker/libChecker.a)

include(CTest)
include(Catch)
catch_discover_tests(Test)