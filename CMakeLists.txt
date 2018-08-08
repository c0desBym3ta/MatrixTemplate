cmake_minimum_required(VERSION 3.10)
project(MatrixAbsFactory)

set(CMAKE_CXX_STANDARD 11)

add_executable(MatrixAbsFactory main.cpp MatrixTemplate.cpp MatrixTemplate.h headers.h ColumnMatrix.h ColumnMatrix.cpp MatrixFactory.cpp MatrixFactory.h MatrixFactoryType.cpp MatrixFactoryType.h RectangularMatrix.h RectangularMatrix.cpp RowMatrix.cpp RowMatrix.h SquareMatrix.h SquareMatrix.cpp)