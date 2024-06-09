cmake_minimum_required(VERSION 3.27)
project(hw_stringview_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw_stringview_test main.cpp
        string_view.h
        string_view.cpp
        main_test.cpp)
