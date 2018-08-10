//
// Created by m3taprog on 09/08/18.
//

#ifndef MATRIXABSFACTORY_MATRIXUTILS_H
#define MATRIXABSFACTORY_MATRIXUTILS_H

#include "headers.h"
#include "MatrixTemplate.h"

template <class T>
class MatrixUtils {
public:
    void printListOfMatrix(std::list<MatrixTemplate<T>*>& listOfMatrix);
};


#endif //MATRIXABSFACTORY_MATRIXUTILS_H
