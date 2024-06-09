cmake_minimum_required(VERSION 3.27)
project(hw_Rational)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw_Rational rational.cpp
        rational.h
        main_test.cpp
)
