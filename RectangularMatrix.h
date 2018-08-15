//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_RECTANGULARMATRIX_H
#define MATRIXABSFACTORY_RECTANGULARMATRIX_H

#include "MatrixTemplate.h"

template <class T>
class RectangularMatrix : public MatrixTemplate<T> {
public:
    RectangularMatrix(int r, int c) throw(std::range_error);
    virtual ~RectangularMatrix();
};


template <class T>
RectangularMatrix<T>::RectangularMatrix(int r, int c) throw(std::range_error) :  MatrixTemplate<T>(r,c){
    if(this->_rows == this->_columns || this->_rows <=0 || this->_columns <= 0)
        throw std::range_error("ERROR Rectangula matrix: Rows and columns must not be equal or 0.");
    this->setMatrixName("RECTANGURAL");
    // std::cout << "\t" << this->getMatrixName() << std::endl;
}

template <class T>
RectangularMatrix<T>::~RectangularMatrix() {

}

#endif //MATRIXABSFACTORY_RECTANGULARMATRIX_H
