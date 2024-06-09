cmake_minimum_required(VERSION 3.27)
project(sr)

set(CMAKE_CXX_STANDARD 17)

add_executable(sr main.cpp
        matrix.h
        matrix.cpp
        matrix_arythm.cpp)
