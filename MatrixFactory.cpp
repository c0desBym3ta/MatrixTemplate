//
// Created by m3taprog on 08/08/18.
//


#include "MatrixFactory.h"

template <class T>
MatrixFactory<T>::MatrixFactory() {
    std::cout << "Loading matrix resources..." << std::endl;
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

/*template <class T>
std::unique_ptr<MatrixTemplate<T>> MatrixFactory<T>::createMatrix(int r, int c) {
    std::unique_ptr<MatrixTemplate<T>> matrixType;
    if(r == 1 && c > 0)
        matrixType = std::unique_ptr<MatrixTemplate<T>>(new RowMatrix(r,c));
    else if(r > 0 && c == 1)
        matrixType == std::unique_ptr<MatrixTemplate<T>>(new ColumnMatrix(r,c));
    else
        std::cout << "Some error at create matrix method." << std::endl;
    return matrixType;
}
 */