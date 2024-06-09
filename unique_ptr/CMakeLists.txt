cmake_minimum_required(VERSION 3.27)
project(unique_ptr)

set(CMAKE_CXX_STANDARD 20)

add_executable(unique_ptr main.cpp
        unique_ptr.cpp
        unique_ptr.h
        git_test/main.cpp
        git_test/main.cpp)
