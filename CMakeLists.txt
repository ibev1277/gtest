cmake_minimum_required(VERSION 3.10)
project(DataStructuresTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests main.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
