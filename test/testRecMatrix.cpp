//
// Created by m3taprog on 15/08/18.
//
#include "gtest/gtest.h"

#include "../MatrixFactoryType.h"

TEST(MatrixTemplate, testRectangularMatrix){
    EXPECT_THROW(RectangularMatrix<int> testMatrix(2,2), std::range_error);
    bool anwser = false;
    RectangularMatrix<int> recMatrix(2,3);
    if((recMatrix.getRows() != recMatrix.getColumns()) && (recMatrix.getColumns() > 0) && (recMatrix.getRows() > 0))
        anwser = true;
    ASSERT_EQ(anwser,true);
}
