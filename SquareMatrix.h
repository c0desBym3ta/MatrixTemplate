//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_SQUAREMATRIX_H
#define MATRIXABSFACTORY_SQUAREMATRIX_H

#include "MatrixTemplate.h"

template <class T>
class SquareMatrix : public MatrixTemplate<T> {
public:
    SquareMatrix(int r, int c) throw(std::range_error);
    virtual ~SquareMatrix();
};

template <class T>
SquareMatrix<T>::SquareMatrix(int r, int c) throw(std::range_error) : MatrixTemplate<T>(r,c) {
    if(this->_rows != this->_columns)
        throw std::range_error("ERROR Square matrix: Rows must equal with columns or 0.");
    this->setMatrixName("SQUARE");
    //std::cout << "\t" << this->getMatrixName() << std::endl;
}

template <class T>
SquareMatrix<T>::~SquareMatrix() {

}


#endif //MATRIXABSFACTORY_SQUAREMATRIX_H
