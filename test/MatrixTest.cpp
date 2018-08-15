#include "gtest/gtest.h"

#include "../MatrixFactoryType.h"


/*=============CONSTRUCTOR-DESTRUCTOR TESTING=================*/
TEST(MatrixTemplate, testConstructor){
    MatrixTemplate<int> testMatrix(3,3);
    testMatrix.printMatrix();
    bool anwser = true;
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++){
            if(testMatrix.elementPosition(i,j) != 0)
                anwser = false;
            else
                anwser = true;
    }
    ASSERT_EQ(anwser, true);
}

TEST(MatrixTemplate, testConstructorThrowException){
    ASSERT_THROW(MatrixTemplate<int> testMatrix(0,0), std::out_of_range);
}
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

/*===================FUCNTION TESTING===============*/
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
TEST(MatrixTemplate, testElementPosition){
    MatrixTemplate<int> firstMatrix(2,2);
    firstMatrix.modifyElement(1,1,1);
    firstMatrix.modifyElement(1,2,1);
    firstMatrix.modifyElement(2,1,1);
    firstMatrix.modifyElement(2,2,1);
    firstMatrix.printMatrix();
    firstMatrix.modifyElement(1,1,5);
    ASSERT_TRUE(firstMatrix.elementPosition(1,1) == 5);
    ASSERT_EQ(5, firstMatrix.elementPosition(1,1));
}
TEST(MatrixTemplate, testMofidyElement){
    MatrixTemplate<int> testMatrix(2,2);
    testMatrix.randomMatrix();
    testMatrix.modifyElement(2,2,200);
    ASSERT_TRUE(testMatrix.elementPosition(2,2) == 200);
    ASSERT_EQ(200, testMatrix.elementPosition(2,2));
}
TEST(MatrixTemplate, testGetRows){
    MatrixTemplate<int> testMatrix(3,2);
    ASSERT_TRUE(testMatrix.getRows() == 3);
}
TEST(MatrixTemplate, testGetColumns){
    MatrixTemplate<int> testMatrix(3,2);
    ASSERT_TRUE(testMatrix.getColumns() == 2);
}
TEST(MatrixTemplate, testMatrixName){
    MatrixTemplate<int> testMatrix(2,2);
    testMatrix.setMatrixName("TEST");
    ASSERT_EQ("TEST", testMatrix.getMatrixName());
}
TEST(MatrixTemplate, testRestOfSetters){
    MatrixTemplate<int> testMatrix(1,1);
    testMatrix.setMatrixName("TEST");
    testMatrix.setRows(3);
    testMatrix.setColumns(2);
    ASSERT_TRUE(testMatrix.getRows() == 3);
    ASSERT_TRUE(testMatrix.getColumns() == 2);
    ASSERT_TRUE(testMatrix.getMatrixName().compare("TEST") == 0);
}
