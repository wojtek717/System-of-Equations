cmake_minimum_required(VERSION 3.9)
project(SystemOfEquations)

set(CMAKE_CXX_STANDARD 17)

add_executable(SystemOfEquations main.cpp
    Consts.h
    Vector.h
    SystemOfEquations.h
    Matrix.h)
