//
// Created by m3taprog on 15/08/18.
//

#include "gtest/gtest.h"

#include "../MatrixFactoryType.h"

TEST(MatrixTemplate, testSquareMatrix){
    //ASSERT_THROW();
    EXPECT_THROW(SquareMatrix<int> squareMatrix(2,3), std::range_error);
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* squareMarix = matrixFactory->selectMatrixType(2,2);
    bool anwser = false;
    if(squareMarix->getRows() == squareMarix->getColumns() && squareMarix->getRows() > 0 && squareMarix->getColumns() > 0)
        anwser = true;
    ASSERT_EQ(anwser, true);
}