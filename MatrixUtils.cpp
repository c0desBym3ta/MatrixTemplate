//
// Created by m3taprog on 09/08/18.
//

#include "MatrixUtils.h"

template <class T>
void MatrixUtils<T>::printListOfMatrix(std::list<MatrixTemplate<T>*>& listOfMatrix) {
    for(auto itr : listOfMatrix) {
        (itr)->printMatrix();
    }
}