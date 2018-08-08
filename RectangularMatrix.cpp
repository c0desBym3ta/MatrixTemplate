//
// Created by m3taprog on 08/08/18.
//

#include "RectangularMatrix.h"

template <class T>
RectangularMatrix<T>::RectangularMatrix(int r, int c) :  MatrixTemplate<T>(r,c){
    this->setMatrixName("RECTANGURAL MATRIX");
   // std::cout << "\t" << this->getMatrixName() << std::endl;
}

template <class T>
RectangularMatrix<T>::~RectangularMatrix() {

}