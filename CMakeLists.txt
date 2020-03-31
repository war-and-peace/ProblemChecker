cmake_minimum_required(VERSION 3.0.0)
project(ProblemChecker VERSION 0.1.0)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)
