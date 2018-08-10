cmake_minimum_required(VERSION 3.10)
project(MatrixAbsFactory)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp MatrixTemplate.cpp MatrixTemplate.h headers.h ColumnMatrix.h ColumnMatrix.cpp MatrixFactory.cpp MatrixFactory.h MatrixFactoryType.cpp MatrixFactoryType.h RectangularMatrix.h RectangularMatrix.cpp RowMatrix.cpp RowMatrix.h SquareMatrix.h SquareMatrix.cpp Utils.cpp Utils.h MatrixUtils.cpp MatrixUtils.h)
add_executable(MatrixAbsFactory main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(MatrixAbsFactory core)
