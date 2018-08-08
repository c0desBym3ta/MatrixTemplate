//
// Created by m3taprog on 08/08/18.
//

#include "SquareMatrix.h"

template <class T>
SquareMatrix<T>::SquareMatrix(int r, int c) : MatrixTemplate<T>(r,c) {
    this->setMatrixName("SQUARE MATRIX");
    //std::cout << "\t" << this->getMatrixName() << std::endl;
}

template <class T>
SquareMatrix<T>::~SquareMatrix() {

}