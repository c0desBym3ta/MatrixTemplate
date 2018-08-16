//
// Created by m3taprog on 15/08/18.
//
#include "gtest/gtest.h"

#include "../MatrixFactoryType.h"

TEST(RectangularMatrix, testRectangularMatrix){
    //EXPECT_THROW(RectangularMatrix<int> testMatrix(2,2), std::out_of_range);
    bool anwser = false;
    RectangularMatrix<int> recMatrix(2,3);
    if((recMatrix.getRows() != recMatrix.getColumns()) && (recMatrix.getColumns() > 0) && (recMatrix.getRows() > 0))
        anwser = true;
    ASSERT_EQ(anwser,true);
}
