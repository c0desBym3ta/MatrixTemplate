//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_MATRIXFACTORYTYPE_H
#define MATRIXABSFACTORY_MATRIXFACTORYTYPE_H

#include "MatrixFactory.h"


template <class T>
class MatrixFactoryType : public MatrixFactory<T>{
public:
    virtual MatrixTemplate<T>* createMatrix(int c, int r) override;
    //virtual std::unique_ptr<MatrixTemplate<T>> createMatrix(int r, int c) override ;
};


#endif //MATRIXABSFACTORY_MATRIXFACTORYTYPE_H
