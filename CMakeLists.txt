cmake_minimum_required(VERSION 3.21)
project(Sorting)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sorting main.cpp handling.cpp handling.h intro.cpp intro.h quick.cpp quick.h merge.cpp merge.h)
