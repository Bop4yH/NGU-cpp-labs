cmake_minimum_required(VERSION 3.14)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1 catch.h main.cpp TritSet.cpp TritSet.h tests-main.cpp TESTs.cpp)