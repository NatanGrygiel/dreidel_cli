cmake_minimum_required(VERSION 3.28)
project(dreidel_cli)

set(CMAKE_CXX_STANDARD 20)

add_executable(dreidel_cli main.cpp
        dreidel.h)
