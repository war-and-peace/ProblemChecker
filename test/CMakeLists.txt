find_package(Catch2 REQUIRED)
add_executable(Test test.cpp)
target_link_libraries(Test Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(Test)