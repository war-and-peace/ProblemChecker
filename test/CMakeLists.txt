include_directories(../src/checker)
add_executable(Test test_checkers.cpp)

add_subdirectory(ext/Catch2)
target_link_libraries(Test Catch2::Catch2)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/ext/Catch2/contrib")
include(CTest)
include(Catch)
catch_discover_tests(Test)