cmake_minimum_required(VERSION 3.10)
project(CalculatorProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(calc main.cpp calculator.cpp shape.cpp)

add_executable(run_tests test_main.cpp  calculator.cpp shape.cpp)

target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)

add_test(NAME AllTests COMMAND run_tests)

