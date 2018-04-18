cmake_minimum_required(VERSION 3.9)
project(RLP C)

set(CMAKE_C_STANDARD 99)

add_executable(RLP main.c RLP.c RLP.h utils.c utils.h)