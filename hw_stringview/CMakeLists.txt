cmake_minimum_required(VERSION 3.27)
project(hw_stringview)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw_stringview string_view.cpp
        string_view.h
        main_test.cpp)
