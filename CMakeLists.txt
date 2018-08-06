cmake_minimum_required(VERSION 3.10)
project(MatrixAbsFactory)

set(CMAKE_CXX_STANDARD 11)

add_executable(MatrixAbsFactory main.cpp headers.h MatrixTemplate.cpp MatrixTemplate.h)