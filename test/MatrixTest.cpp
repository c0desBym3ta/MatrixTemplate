#include "gtest/gtest.h"
#include "../MatrixFactory.h"
#include "../MatrixFactoryType.h"

TEST(MatrixTemplate, testSquare) {
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* squareMatrix = matrixFactory->selectMatrixType(3,3);
    ASSERT_EQ(squareMatrix->getMatrixName() == "SQUARE",true);
}
