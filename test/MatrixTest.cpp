#include "gtest/gtest.h"

#include "../MatrixFactoryType.h"

TEST(MatrixTemplate, testSquareMatrix){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* squareMarix = matrixFactory->selectMatrixType(2,2);
    bool anwser = false;
    if(squareMarix->getRows() == squareMarix->getColumns())
        anwser = true;
    ASSERT_EQ(anwser, true);
}

TEST(MatrixTemplate, testRecMatrix){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* recMatrix = matrixFactory->selectMatrixType(2,3);
    bool anwser = false;
    if(recMatrix->getColumns() != recMatrix->getRows() && recMatrix->getRows() > 1 && recMatrix->getColumns() >1)
        anwser = true;
    ASSERT_EQ(anwser, true);
}

TEST(MatrixTemplate, testOperatorMul){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(2,2);
    firstMatrix->randomMatrix();
    firstMatrix->modifyElement(1,1,2);
    firstMatrix->modifyElement(1,2,2);
    firstMatrix->modifyElement(2,1,2);
    firstMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(2,2);
    secondMatrix->modifyElement(1,1,2);
    secondMatrix->modifyElement(1,2,2);
    secondMatrix->modifyElement(2,1,2);
    secondMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* resMatrix = matrixFactory->selectMatrixType(2,2);
    (*resMatrix) = (*firstMatrix)*(*secondMatrix);
    ASSERT_EQ(8,resMatrix->elementPosition(1,1));
    ASSERT_EQ(8,resMatrix->elementPosition(1,2));
    ASSERT_EQ(8,resMatrix->elementPosition(2,1));
    ASSERT_EQ(8,resMatrix->elementPosition(2,2));
}

TEST(MatrixTemplate, testOperatorPlus){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(2,2);
    firstMatrix->randomMatrix();
    firstMatrix->modifyElement(1,1,2);
    firstMatrix->modifyElement(1,2,2);
    firstMatrix->modifyElement(2,1,2);
    firstMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(2,2);
    secondMatrix->modifyElement(1,1,2);
    secondMatrix->modifyElement(1,2,2);
    secondMatrix->modifyElement(2,1,2);
    secondMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* resMatrix = matrixFactory->selectMatrixType(2,2);
    (*resMatrix) = (*firstMatrix)+(*secondMatrix);
    ASSERT_EQ(4,resMatrix->elementPosition(1,1));
    ASSERT_EQ(4,resMatrix->elementPosition(1,2));
    ASSERT_EQ(4,resMatrix->elementPosition(2,1));
    ASSERT_EQ(4,resMatrix->elementPosition(2,2));
}

TEST(MatrixTemplate, testOperatorMulNum){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(2,2);
    firstMatrix->randomMatrix();
    firstMatrix->modifyElement(1,1,2);
    firstMatrix->modifyElement(1,2,2);
    firstMatrix->modifyElement(2,1,2);
    firstMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(2,2);
    *secondMatrix = (*firstMatrix)*2;
    ASSERT_EQ(4,secondMatrix->elementPosition(1,1));
    ASSERT_EQ(4,secondMatrix->elementPosition(1,2));
    ASSERT_EQ(4,secondMatrix->elementPosition(2,1));
    ASSERT_EQ(4,secondMatrix->elementPosition(2,2));
}

TEST(MatrixTemplate, testOperatorDivNum){
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>;
    MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(2,2);
    firstMatrix->randomMatrix();
    firstMatrix->modifyElement(1,1,2);
    firstMatrix->modifyElement(1,2,2);
    firstMatrix->modifyElement(2,1,2);
    firstMatrix->modifyElement(2,2,2);
    MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(2,2);
    *secondMatrix = (*firstMatrix)/2;
    ASSERT_EQ(1,secondMatrix->elementPosition(1,1));
    ASSERT_EQ(1,secondMatrix->elementPosition(1,2));
    ASSERT_EQ(1,secondMatrix->elementPosition(2,1));
    ASSERT_EQ(1,secondMatrix->elementPosition(2,2));
}

TEST(MatrixTemplate, testOperatorEqual){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.modifyElement(1,1,2);
    firstMatrix.modifyElement(1,2,2);
    firstMatrix.modifyElement(2,1,2);
    firstMatrix.modifyElement(2,2,2);
    MatrixTemplate<int> secondMatrix = firstMatrix;
    ASSERT_TRUE(firstMatrix==secondMatrix);
}

TEST(MatrixTemplate, testOperatorNotEquall){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.modifyElement(1,1,2);
    firstMatrix.modifyElement(1,2,2);
    firstMatrix.modifyElement(2,1,2);
    firstMatrix.modifyElement(2,2,2);
    MatrixTemplate<int> secondMatrix(2,2);
    secondMatrix.modifyElement(1,1,2);
    secondMatrix.modifyElement(1,2,2);
    secondMatrix.modifyElement(2,1,2);
    secondMatrix.modifyElement(2,2,1);
    ASSERT_TRUE(firstMatrix!=secondMatrix);
}

TEST(MatrixTemplate, testSelectRow){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.randomMatrix();
    MatrixTemplate<int> rowMatrix = firstMatrix.selectRow(1);
    ASSERT_EQ(firstMatrix.elementPosition(1,1), rowMatrix.elementPosition(1,1));
    ASSERT_EQ(firstMatrix.elementPosition(1,2), rowMatrix.elementPosition(1,2));
    ASSERT_EQ(firstMatrix.getColumns(), rowMatrix.getColumns());
    ASSERT_FALSE(firstMatrix.getRows()==rowMatrix.getRows());
}

TEST(MatrixTemplate, testSelectColumn){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.randomMatrix();
    MatrixTemplate<int> colMatrix = firstMatrix.selectColumn(1);
    ASSERT_EQ(firstMatrix.elementPosition(1,1), colMatrix.elementPosition(1,1));
    ASSERT_EQ(firstMatrix.elementPosition(2,1), colMatrix.elementPosition(2,1));
    ASSERT_EQ(firstMatrix.getRows(), colMatrix.getRows());
    ASSERT_FALSE(firstMatrix.getColumns()==colMatrix.getColumns());
}

TEST(MatrixTemplate, testTranspose){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.randomMatrix();
    MatrixTemplate<int> transposeMatrix = firstMatrix.getTranspose();
    ASSERT_EQ(firstMatrix.elementPosition(1,1), transposeMatrix.elementPosition(1,1));
    ASSERT_EQ(firstMatrix.elementPosition(1,2), transposeMatrix.elementPosition(2,1));
    ASSERT_EQ(firstMatrix.elementPosition(2,1), transposeMatrix.elementPosition(1,2));
    ASSERT_EQ(firstMatrix.elementPosition(2,2), transposeMatrix.elementPosition(2,2));
}