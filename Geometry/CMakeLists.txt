cmake_minimum_required(VERSION 3.27)
project(geometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(geometry main.cpp
        Point.h
        IShape.h
        Segment.h
        line.h
        ray.h
        polygon.h
        circle.h
        src/Point.cpp
        Vector.h
        src/Vector.cpp
        src/Segment.cpp
        src/ray.cpp
        src/polygon.cpp
        src/line.cpp
        src/circle.cpp
        src/circle.cpp)
