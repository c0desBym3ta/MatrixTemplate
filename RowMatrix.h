//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_ROWMATRIX_H
#define MATRIXABSFACTORY_ROWMATRIX_H

#include "MatrixTemplate.h"

template <class T>
class RowMatrix : public MatrixTemplate<T>{
public:
    RowMatrix(int r, int c, std::string n);
    virtual ~RowMatrix();

};


#endif //MATRIXABSFACTORY_ROWMATRIX_H
