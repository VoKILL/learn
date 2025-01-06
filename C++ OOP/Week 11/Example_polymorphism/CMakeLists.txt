cmake_minimum_required(VERSION 3.29)
project(Example_polymorphism)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Example_polymorphism
    Circle.cpp
    Circle.h
    main.cpp
    Rectangle.cpp
    Rectangle.h
    Shape.cpp
    Shape.h
    Triangle.cpp
    Triangle.h)
