cmake_minimum_required(VERSION 3.10)

#project name
project(ez-tensor VERSION 0.01)

#include("include/*")

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GoogleTest)
find_package(GTest REQUIRED)

add_executable(Test "TestStaticMultiDimensionalArray.cpp")
target_link_libraries(Test gtest pthread)

gtest_discover_tests(Test)
