//
// Created by m3taprog on 08/08/18.
//

#include "RowMatrix.h"

template <class T>
RowMatrix<T>::RowMatrix(int r, int c) : MatrixTemplate<T>(1,c){
    this->setMatrixName("ROW");
    //std::cout <<"\t" << this->getMatrixName() << std::endl;
}

template <class T>
RowMatrix<T>::~RowMatrix() {

}