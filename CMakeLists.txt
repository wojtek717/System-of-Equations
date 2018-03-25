cmake_minimum_required(VERSION 3.9)
project(SystemOfEquations)

set(CMAKE_CXX_STANDARD 11)

add_executable(SystemOfEquations main.cpp Consts.h Vector.cpp Vector.h SystemOfEquations.cpp SystemOfEquations.h Matrix.cpp Matrix.h InputOutput.cpp InputOutput.h)