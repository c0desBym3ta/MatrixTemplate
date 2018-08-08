//
// Created by m3taprog on 08/08/18.
//

#include "MatrixFactoryType.h"
#include "RowMatrix.cpp"
#include "ColumnMatrix.cpp"
#include "SquareMatrix.cpp"
#include "RectangularMatrix.cpp"

template <class T>
MatrixTemplate<T>* MatrixFactoryType<T>::createMatrix(int r, int c){
    MatrixTemplate<T>* matrixTemplate;
    if(r == 1 && c > 0) {
        matrixTemplate = new RowMatrix<T>(r, c);
        matrixTemplate->setMatrixName("ROW MATRIX");
    }else if(r > 0 && c == 1) {
        matrixTemplate = new ColumnMatrix<T>(r, c);
        matrixTemplate->setMatrixName("COLUMN MATRIXA");
    }else if(r == c) {
        matrixTemplate = new SquareMatrix<T>(r, c);
        matrixTemplate->setMatrixName("SQUARE MATRIX");
    }else if(r > 0 && c > 0 && r !=c ) {
        matrixTemplate = new RectangularMatrix<T>(r, c);
        matrixTemplate->setMatrixName("RECTANGULAR MATRIX");
    }else{
        std::cout << "Some error at create matrix matrixFactoryType." << std::endl;
        return nullptr;
    }
    return matrixTemplate;
}

/*
template <class T>
std::unique_ptr<MatrixTemplate<T>> MatrixFactoryType<T>::createMatrix(int r, int c) {
    //std::unique_ptr<MatrixTemplate<T>> matrixTemplate;
    if(r == 1 && c > 0)
        std::unique_ptr<MatrixTemplate<T>> matrixTemplate(new RowMatrix(r,c,"ROW MATRIX"));
}*/