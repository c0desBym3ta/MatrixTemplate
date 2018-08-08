//
// Created by m3taprog on 08/08/18.
//

#include "ColumnMatrix.h"

template <class T>
ColumnMatrix<T>::ColumnMatrix(int r, int c, std::string n) : MatrixTemplate<T>(r,1,n){
    this->setMatrixName("COLUMN MATRIX");
    //std::cout << "\t" << this->getMatrixName() << std::endl;
}

template <class T>
ColumnMatrix<T>::~ColumnMatrix() {

}