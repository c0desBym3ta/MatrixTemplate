//
// Created by m3taprog on 06/08/18.
//

#include "MatrixTemplate.h"

/*Constructors and Destructors.*/
template <class T>
MatrixTemplate<T>::MatrixTemplate(int r, int c) : _rows(r), _columns(c) {
    if (r < 1)
        _rows = 1;
    if (c < 1)
        _columns = 1;

    _buffer = new T[_rows * _columns];
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[i] = i+1;
}

template <class T>
MatrixTemplate<T>::MatrixTemplate(const MatrixTemplate &mt) {copier(mt);}

template <class T>
MatrixTemplate<T>::~MatrixTemplate() {delete [] _buffer;}

/*Matrix operations.*/
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::getTranspose() const{
    MatrixTemplate<T> tmp(_columns, _rows);
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _columns; j++)
            tmp._buffer[tmp._columns * j + i] = _buffer[_columns * i + j];
    return tmp;
}

template <class T>
void MatrixTemplate<T>::printMatrix(MatrixTemplate &matrixTemplate) {
    for(int i = 0; i<_rows; i++) {
        for (int j = 0; j < _columns; j++)
            std::cout << "\t[" << _buffer[j + i * _columns] << "]";
        std::cout << std::endl;
    }
}

template <class T>
void MatrixTemplate<T>::printMatrix() {
    for(int i = 0; i<_rows; i++) {
        for (int j = 0; j < _columns; j++)
            std::cout << "\t[" << _buffer[j + i * _columns] << "]";
        std::cout << std::endl;
    }
}

template <class T>
T MatrixTemplate<T>::elementPosition(int rowPos, int colPos) const {
    T element = _buffer[rowPos + colPos * _columns];
    return element;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::selectRow(int rowNum) {
    if(rowNum>=1){
        MatrixTemplate<T> rowMatrix(1, _columns);
        for(int i = 0; i<_columns; i++)
            rowMatrix._buffer[i] = _buffer[i+_columns*(rowNum-1)];
        return rowMatrix;
    }
    std::cout << "ERROR ROW MATRIX" << std::endl;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::selectColumn(int colNum) {
    if(colNum >= 1){
        MatrixTemplate<T> columnMatrix(_rows, 1);
        for(int j = 0; j<_rows; j++)
            columnMatrix._buffer[j] = _buffer[j+_rows*(colNum-1)];
        return columnMatrix;
    }
    std::cout << "ERROR COLUMNS MATRIX" << std::endl;
}

/*Operator overloading.*/
template <class T>
MatrixTemplate<T>& MatrixTemplate<T>::operator=(const MatrixTemplate<T>& mt) {
    if(this != &mt){
        delete[] _buffer;
        copier(mt);
    }return *this;
}

template <class T>
bool MatrixTemplate<T>::operator==(const MatrixTemplate<T>& mt) const{
    if(_rows == mt._columns && _columns == mt._rows){
        for(int i = 0; i < _rows; i++){
            for(int j = 0; j < _columns; j++)
                if(mt.elementPosition(i,j) != _buffer[j + i * _columns])
                    return true;
            return false;
        }
    }
    return false;
}

template <class T>
bool MatrixTemplate<T>::operator!=(const MatrixTemplate<T> &mt) const {
    return !(*this == mt);
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator+(const MatrixTemplate<T>& mt){
    if(_rows == mt._columns && _columns == mt._rows){
        MatrixTemplate<T> sumMatrix(_rows, _columns);
        for(int i = 0; i<_rows*_columns; i++){
            sumMatrix._buffer[i] = _buffer[i] + mt._buffer[i];
        }
        return sumMatrix;
    }
    std::cout << "ERROR SUM MATRIX" << std::endl;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator*(const MatrixTemplate<T>& mt){
    if(_rows == mt._columns && _columns == mt._rows){
        MatrixTemplate<T> prodMatrix(_rows, _columns);
        for(int i =0; i<_rows*_columns; i++){
            prodMatrix._buffer[i] = _buffer[i] * mt._buffer[i];
        }
        return prodMatrix;
    }
    std::cout << "ERROR PROD MATRIX" << std::endl;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator*(const T& num){
    MatrixTemplate<T> prodNum(_rows,_columns);
    for(int i = 0; i<_rows*_columns; i++)
        prodNum._buffer[i] = num * _buffer[i];
    return prodNum;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator-(const MatrixTemplate<T>& mt){
    if(_rows == mt._columns && _columns == mt._rows){
        MatrixTemplate<T> subMatrix(_rows, _columns);
        for(int i =0; i<_rows*_columns; i++){
            subMatrix._buffer[i] = _buffer[i] - mt._buffer[i];
        }
        return subMatrix;
    }
    std::cout << "ERROR SUB MATRIX" << std::endl;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator/(const MatrixTemplate<T>& mt){
    if(_rows == mt._columns && _columns == mt._rows){
        MatrixTemplate<T> divMatrix(_rows, _columns);
        for(int i =0; i<_rows*_columns; i++){
            divMatrix._buffer[i] = _buffer[i] / mt._buffer[i];
        }
        return divMatrix;
    }
    std::cout << "ERROR DIV MATRIX" << std::endl;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator+=(const MatrixTemplate<T>& mt){
    if(_rows == mt._columns && _columns == mt._rows){
        for(int i =0; i<_rows*_columns; i++){
            _buffer[i] = _buffer[i] + mt._buffer[i];
        }
        return *this;
    }else{
        std::cout << "ERROR += " << std::endl;
    }
}

/*Getters and setters.*/
template <class T>
int MatrixTemplate<T>::getRows() const {
    return _rows;
}

template <class T>
int MatrixTemplate<T>::getColumns() const {
    return _columns;
}

template <class T>
void MatrixTemplate<T>::copier(const MatrixTemplate &mt) {
    _rows = mt._rows;
    _columns = mt._columns;
    _buffer = new T[_rows * _columns];
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[i] = mt._buffer[i];
}