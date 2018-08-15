//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_MATRIXFACTORYTYPE_H
#define MATRIXABSFACTORY_MATRIXFACTORYTYPE_H

#include "MatrixFactory.h"
#include "SquareMatrix.h"
#include "RectangularMatrix.h"


template <class T>
class MatrixFactoryType : public MatrixFactory<T>{
public:
    virtual MatrixTemplate<T>* createMatrix(int c, int r) override;
    //virtual std::unique_ptr<MatrixTemplate<T>> createMatrix(int r, int c) override ;
};

template <class T>
MatrixTemplate<T>* MatrixFactoryType<T>::createMatrix(int r, int c){
    MatrixTemplate<T>* matrixTemplate;
    std::cout << std::endl;
    if(r == 1 && c > 0) {
        matrixTemplate = new RectangularMatrix<T>(1, c);
        std::cout << "You have selected a row (" <<r <<  "x" << c <<  ") matrix." << std::endl;
        matrixTemplate->setMatrixName("ROW");
    }else if(r > 0 && c == 1) {
        matrixTemplate = new RectangularMatrix<T>(r, 1);
        std::cout << "You have selected a column (" <<r <<  "x" << c <<  ") matrix." << std::endl;
        matrixTemplate->setMatrixName("COLUMN");
    }else if(r == c) {
        matrixTemplate = new SquareMatrix<T>(r, c);
        std::cout << "You have selected a square (" <<r <<  "x" << c <<  ") matrix." << std::endl;
        matrixTemplate->setMatrixName("SQUARE");
    }else if(r > 0 && c > 0 && r !=c ) {
        matrixTemplate = new RectangularMatrix<T>(r, c);
        std::cout << "You have selected a rectangular (" <<r <<  "x" << c <<  ") matrix." << std::endl;
        matrixTemplate->setMatrixName("RECTANGULAR");
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

#endif //MATRIXABSFACTORY_MATRIXFACTORYTYPE_H
