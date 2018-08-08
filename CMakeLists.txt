cmake_minimum_required(VERSION 3.10)
project(MatrixAbsFactory)

set(CMAKE_CXX_STANDARD 11)

add_executable(MatrixAbsFactory main.cpp MatrixTemplate.cpp MatrixTemplate.h headers.h RectangularMatrix.cpp RectangularMatrix.h SquareMatrix.cpp SquareMatrix.h RowMatrix.cpp RowMatrix.h ColumnMatrix.cpp ColumnMatrix.h)