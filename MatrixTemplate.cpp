//
// Created by m3taprog on 06/08/18.
//

#include "MatrixTemplate.h"
#include "headers.h"

/*
template <typename T>
MatrixTemplate<T>::MatrixTemplate(int r, int c)  : _rows(r), _columns(c) {
    if (r < 1)
        _rows = 1;
    if (c < 1)
        _columns = 1;

    _buffer = new T[_rows * _columns];
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[0];
}

template <typename T>
void MatrixTemplate<T>::printMatrix(MatrixTemplate& matrixTemplate) {
    for(int i = 0; i<_rows; i++)
        for(int j = 0; j<_columns; j++)
            std::cout << "[" << _buffer[j+i*_columns];
        std::cout << std::endl;
}

template <typename T>
MatrixTemplate<T>::MatrixTemplate(const MatrixTemplate &mt) {
    copier(mt);
}


template <typename T>
void MatrixTemplate<T>::copier(const MatrixTemplate &mt) {
    _rows = mt._rows;
    _columns = mt._columns;
    _buffer = new T[_rows * _columns];
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[i] = mt._buffer[i];
}

template <typename T>
MatrixTemplate<T>::~MatrixTemplate() {
    delete [] _buffer;
}
 */