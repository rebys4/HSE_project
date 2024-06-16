cmake_minimum_required(VERSION 3.27)
project(shared_ptr)

set(CMAKE_CXX_STANDARD 20)

add_executable(shared_ptr
        shared_ptr.h
        shared_ptr_public_test.cpp)
