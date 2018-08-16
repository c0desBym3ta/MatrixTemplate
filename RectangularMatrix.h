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
   try {
        if (this->_rows == this->_columns || this->_rows <= 0 || this->_columns <= 0) {
            std::cout << "Throwing" << std::endl;
            throw std::out_of_range("ERROR Rectangula matrix: Rows and columns must not be equal or 0.");
        }
    }catch (std::out_of_range& e){
        e.what();
    }
    std::cout << "Not throwing" << std::endl;
    this->setMatrixName("RECTANGURAL");
}

template <class T>
RectangularMatrix<T>::~RectangularMatrix() {

}

#endif //MATRIXABSFACTORY_RECTANGULARMATRIX_H