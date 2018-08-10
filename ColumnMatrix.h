//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_COLUMNMATRIX_H
#define MATRIXABSFACTORY_COLUMNMATRIX_H

#include "MatrixTemplate.h"

template <class T>
class ColumnMatrix : public MatrixTemplate<T>{
public:
    ColumnMatrix(int r, int c);
    virtual ~ColumnMatrix();

};


#endif //MATRIXABSFACTORY_COLUMNMATRIX_H
