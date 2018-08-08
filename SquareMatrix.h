//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_SQUAREMATRIX_H
#define MATRIXABSFACTORY_SQUAREMATRIX_H

#include "MatrixTemplate.h"

template <class T>
class SquareMatrix : public MatrixTemplate<T> {
public:
    SquareMatrix(int r, int c, std::string n);
    virtual ~SquareMatrix();
};


#endif //MATRIXABSFACTORY_SQUAREMATRIX_H
