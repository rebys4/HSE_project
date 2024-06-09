cmake_minimum_required(VERSION 3.27)
project(geometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(geometry main.cpp
        Point.h
        IShape.h
        Segment.h
        Line.h
        Ray.h
        Polygon.h
        Circle.h
        src/Point.cpp
        Vector.h
        src/Vector.cpp
        src/Segment.cpp)
