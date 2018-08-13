cmake_minimum_required(VERSION 3.10)
project(MatrixAbsFactory)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp MatrixTemplate.h headers.h ColumnMatrix.h MatrixFactory.h MatrixFactoryType.h RectangularMatrix.h RowMatrix.h SquareMatrix.h Utils.cpp Utils.h MatrixUtils.h)
add_executable(MatrixAbsFactory main.cpp)
