//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_MATRIXFACTORY_H
#define MATRIXABSFACTORY_MATRIXFACTORY_H

#include "MatrixTemplate.h"
#include <memory>

template <class T>
class MatrixFactory {
public:
    MatrixFactory();
    virtual ~MatrixFactory();

    MatrixTemplate<T>* selectMatrixType(int r, int c);
    virtual MatrixTemplate<T>* createMatrix(int r, int c) = 0;
};


#endif //MATRIXABSFACTORY_MATRIXFACTORY_H
