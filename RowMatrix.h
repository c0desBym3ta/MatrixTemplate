//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_ROWMATRIX_H
#define MATRIXABSFACTORY_ROWMATRIX_H

#include "MatrixTemplate.h"

template <class T>
class RowMatrix : public MatrixTemplate<T>{
public:
    RowMatrix(int r, int c);
    virtual ~RowMatrix();

};


template <class T>
RowMatrix<T>::RowMatrix(int r, int c) : MatrixTemplate<T>(1,c){
    this->setMatrixName("ROW");
    //std::cout <<"\t" << this->getMatrixName() << std::endl;
}

template <class T>
RowMatrix<T>::~RowMatrix() {

}


#endif //MATRIXABSFACTORY_ROWMATRIX_H
