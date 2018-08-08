//
// Created by m3taprog on 08/08/18.
//

#include "ColumnMatrix.h"

template <class T>
ColumnMatrix<T>::ColumnMatrix(int r, int c) : MatrixTemplate<T>(r,1){
    this->setMatrixName("COLUMN MATRIX");
}

template <class T>
ColumnMatrix<T>::~ColumnMatrix() {

}