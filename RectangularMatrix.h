//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_RECTANGULARMATRIX_H
#define MATRIXABSFACTORY_RECTANGULARMATRIX_H

#include "MatrixTemplate.h"

template <class T>
class RectangularMatrix : public MatrixTemplate<T> {
public:
    RectangularMatrix(int r, int c);
    virtual ~RectangularMatrix();
};


template <class T>
RectangularMatrix<T>::RectangularMatrix(int r, int c) :  MatrixTemplate<T>(r,c){
    this->setMatrixName("RECTANGURAL");
    // std::cout << "\t" << this->getMatrixName() << std::endl;
}

template <class T>
RectangularMatrix<T>::~RectangularMatrix() {

}

#endif //MATRIXABSFACTORY_RECTANGULARMATRIX_H
