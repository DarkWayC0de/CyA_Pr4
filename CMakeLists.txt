cmake_minimum_required(VERSION 3.12)
project(Pr4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Pr4
    Block.cpp
    Block.h
    main.cpp
    Row.cpp
    Row.h
    Wall.cpp
    Wall.h)
