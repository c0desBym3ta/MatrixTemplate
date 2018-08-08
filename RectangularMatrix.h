//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_RECTANGULARMATRIX_H
#define MATRIXABSFACTORY_RECTANGULARMATRIX_H

#include "MatrixTemplate.h"

template <class T>
class RectangularMatrix : public MatrixTemplate<T> {
public:
    RectangularMatrix(int r, int c, std::string n);
    virtual ~RectangularMatrix();
};


#endif //MATRIXABSFACTORY_RECTANGULARMATRIX_H
