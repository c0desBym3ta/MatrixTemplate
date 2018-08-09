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
    srand((unsigned)time(0));
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[i] = (rand()%10)+1;
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
void MatrixTemplate<T>::printMatrix(std::string matrixName) {
    std::cout << "\n\t" << matrixName << " MATRIX   " << std::endl;
    std::cout << "\t";
    for(unsigned short int i =0; i != matrixName.size(); i++)
        std::cout << "-";
    std::cout << "-------" << std::endl;
    for(int i = 0; i<_rows; i++) {
        for (int j = 0; j < _columns; j++)
            std::cout << "\t[" << _buffer[j + i * _columns] << "]";
        std::cout << std::endl;
    }
}

template <class T>
void MatrixTemplate<T>::printMatrix() {
    std::cout << "\n\t" << this->_matrixName << " MATRIX" << std::endl;
    std::cout << "\t";
    for(unsigned short int i =0; i != this->_matrixName.size(); i++)
        std::cout << "-";
    std::cout << "-------" << std::endl;
    for(int i = 0; i<_rows; i++) {
        for (int j = 0; j < _columns; j++)
            std::cout << "\t[" << _buffer[j + i * _columns] << "]";
        std::cout << std::endl;
    }

}

template <class T>
T MatrixTemplate<T>::elementPosition(int rowPos, int colPos) const {
    T element = _buffer[(colPos-1) + (rowPos-1) * _columns];
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

template <class T>
void MatrixTemplate<T>::modifyElement(int rowNum, int colNum, const T& newValue) {
    if(_columns > 0 || _rows > 0)
        _buffer[(rowNum-1)* _columns + (colNum-1)] = newValue;
}

/*
template<class T>
MatrixTemplate<T> MatrixTemplate<T>::swapRows(int i, int j) {

}
 */

template<class T>
void MatrixTemplate<T>::manualInsertValues(MatrixTemplate &newMatrixTemplate) {
    std::cout << std:: endl;
    T value;
    for(int i = 0; i<_rows; i++){
        for(int j = 0; j <_columns; j++){
            std::cout << "Insert element at Matrix[" << i+1 << "]["<< j+1 << "]:"; std::cin >> value;
            _buffer[j+i*_columns] = value;
        }
    }

}

template <class T>
void MatrixTemplate<T>::matrixOfZeros() {
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[i] = 0;
}

template <class T>
void MatrixTemplate<T>::randomMatrix() {
    srand((unsigned)time(0));
    for(int i = 0; i <_rows*_columns; i++)
        _buffer[i] = (rand()%10)+1;
}

template <class T>
void MatrixTemplate<T>::sequenceMatrix() {
    for(int i = 0; i<_rows*_columns; i++)
        _buffer[i] = i+1;
}

template<class T>
void MatrixTemplate<T>::manualInsertValues() {
    T value;
    std::cout << std::endl;
    for(int i = 0; i<_rows; i++){
        for(int j = 0; j <_columns; j++){
            std::cout << "Insert element at Matrix[" << i+1 << "]["<< j+1 << "]:"; std::cin >> value;
            _buffer[j+i*_columns] = value;
        }
    }
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
    if(_rows == mt._rows || _columns == mt._columns) {
        for (int i = 0; i < _rows * _columns; i++)
            if (_buffer[i] != mt._buffer[i])
                return false;
    }
    return true;
}

template <class T>
bool MatrixTemplate<T>::operator!=(const MatrixTemplate<T>& mt) const {
    return !(*this == mt);
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator+(const MatrixTemplate<T>& mt){
    if (_rows == mt._rows && _columns == mt._columns) {
        MatrixTemplate<T> sumMatrix(_rows, _columns);
        for (int i = 0; i < _rows * _columns; i++) {
            sumMatrix._buffer[i] = _buffer[i] + mt._buffer[i];
        }
        return sumMatrix;
    }
    std::cout << "ERROR SUM MATRIX" << std::endl;
   // return mt;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator*(const MatrixTemplate<T> &mt) const {
    try {
        if (_rows == mt._columns) {
            MatrixTemplate<T> prodMatrix(_rows, mt._columns);
            for (int i = 0; i < _rows; i++)
                for (int j = 0; j < mt._columns; j++) {
                    prodMatrix._buffer[i * mt._columns + j] = 0;
                    for (int h = 0; h < _columns; h++)
                        prodMatrix._buffer[i * mt._columns + j] +=
                                _buffer[i * _columns + h] * mt._buffer[h * mt._columns + j];
                }
            return prodMatrix;
        }else{
            throw std::out_of_range("ERROR -1: First matrix row number not equal qith second's matrix columns number.");
        }
    }catch (std::out_of_range& e){
        e.what();
       // return mt;
    }

}

/*
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator*(const MatrixTemplate<T>& mt){
    if(_rows == mt._columns ){
        MatrixTemplate<T> prodMatrix(_rows, mt._columns);
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < mt._columns; j++) {
                prodMatrix._buffer[i * mt._columns + j] = 0;
                for (int h = 0; h < _columns; h++)
                    prodMatrix._buffer[i * mt._columns + j] += _buffer[i * _columns + h] * mt._buffer[h * mt._columns + j];
            }
        return prodMatrix;
    }
    std::cout << "ERROR PROD MATRIX" << std::endl;
}
*/
template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator*(const T& num){
    MatrixTemplate<T> prodNum(_rows,_columns);
    for(int i = 0; i<_rows*_columns; i++)
        prodNum._buffer[i] = num * _buffer[i];
    return prodNum;
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
    //return mt;
    std::cout << "ERROR DIV MATRIX" << std::endl;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator/(const T &num) {
    MatrixTemplate<T> divNum(_rows,_columns);
    for(int i = 0; i <_rows*_columns; i++)
        divNum._buffer[i] = _buffer[i]/num;
    return divNum;
}

template <class T>
MatrixTemplate<T> MatrixTemplate<T>::operator-(const MatrixTemplate<T>& mt){
    MatrixTemplate<T> subMatrix(_rows, _columns);
    if(_rows == mt._columns && _columns == mt._rows){
        //MatrixTemplate<T> subMatrix(_rows, _columns);
        for(int i =0; i<_rows*_columns; i++){
            subMatrix._buffer[i] = _buffer[i] - mt._buffer[i];
        }
        return subMatrix;
    }
    std::cout << "ERROR SUB MATRIX" << std::endl;
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
        //return mt;
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

template<class T>
const std::string &MatrixTemplate<T>::getMatrixName() const {
    return _matrixName;
}

template<class T>
void MatrixTemplate<T>::setMatrixName(const std::string &_matrixName) {
    this->_matrixName = _matrixName;
}

template<class T>
void MatrixTemplate<T>::setRows(int _rows) {
    this->_rows = _rows;
}

template<class T>
void MatrixTemplate<T>::setColumns(int _columns) {
    this->_columns = _columns;
}
