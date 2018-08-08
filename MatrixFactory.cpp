//
// Created by m3taprog on 08/08/18.
//


#include "MatrixFactory.h"

template <class T>
MatrixFactory<T>::MatrixFactory() {
    std::cout << "\nLoading matrix resources..." << std::endl;
}
template <class T>
MatrixFactory<T>::~MatrixFactory() {

}

template <class T>
MatrixTemplate<T>* MatrixFactory<T>::selectMatrixType(int r, int c) {
    MatrixTemplate<T>* matrix;
    matrix = createMatrix(r,c);
    return matrix;
}

