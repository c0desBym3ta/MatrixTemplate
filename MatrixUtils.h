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
    void deleteList(std::list<MatrixTemplate<T>*>& listOfMatrix);
};

template <class T>
void MatrixUtils<T>::printListOfMatrix(std::list<MatrixTemplate<T>*>& listOfMatrix) {
    for(auto itr : listOfMatrix) {
        std::cout << "\nID: {" << itr->getMatrixId() << "}\t";
        (itr)->printMatrix();
    }
}
template <class T>
void MatrixUtils<T>::deleteList(std::list<MatrixTemplate<T> *> &listOfMatrix) {
    if(!listOfMatrix.empty()) {
        for (auto itr : listOfMatrix) {
            delete[] itr;
        }
    }
    std::cout << "\nSuccessfully  deallocation." << std::endl;
}
#endif //MATRIXABSFACTORY_MATRIXUTILS_H