//
// Created by m3taprog on 06/08/18.
//

#ifndef MATRIXABSFACTORY_MATRIXTEMPLATE_H
#define MATRIXABSFACTORY_MATRIXTEMPLATE_H

#include "headers.h"

template <typename T>
class MatrixTemplate {
public:
    /*Constructors.*/
    MatrixTemplate(int r, int c) : _rows(r), _columns(c) {
            if (r < 1)
                _rows = 1;
            if (c < 1)
                _columns = 1;

            _buffer = new T[_rows * _columns];
            for(int i = 0; i <_rows*_columns; i++)
                _buffer[i] = i+1;
    }
    MatrixTemplate(const MatrixTemplate& mt){copier(mt);}


    /*Matrix Operations*/
    MatrixTemplate getTranspose() const{
        MatrixTemplate<T> tmp(_columns, _rows);
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _columns; j++)
                tmp._buffer[tmp._columns * j + i] = _buffer[_columns * i + j];
        return tmp;

    }

    void printMatrix(MatrixTemplate& matrixTemplate) {
        for(int i = 0; i<_rows; i++) {
            for (int j = 0; j < _columns; j++)
                std::cout << "\t[" << _buffer[j + i * _columns] << "]";
            std::cout << std::endl;
        }
    }
    void printMatrix(){
        for(int i = 0; i<_rows; i++) {
            for (int j = 0; j < _columns; j++)
                std::cout << "\t[" << _buffer[j + i * _columns] << "]";
            std::cout << std::endl;
        }
    }
    T elementPosition(int rowPos, int colPos) const{
        T element = _buffer[rowPos + colPos * _columns];
        return element;
    }



    /*Operator overloading*/
    MatrixTemplate<T>& operator=(const MatrixTemplate<T>& mt) {
        if(this != &mt){
            delete[] _buffer;
            copier(mt);
        }return *this;
    }
    bool operator==(const MatrixTemplate<T>& mt) const{
        if(_rows == mt._columns){
            for(int i = 0; i < _rows; i++){
                for(int j = 0; j < _columns; j++)
                    if(mt.elementPosition(i,j) != _buffer[j + i * _columns])
                        return true;
            return false;
            }
        }
        return true;
    }
    MatrixTemplate<T> operator+(const MatrixTemplate<T>& mt){
        if(_rows == mt._columns){
            MatrixTemplate<T> sumMatrix(_rows, _columns);
            for(int i = 0; i<_rows*_columns; i++){
                sumMatrix._buffer[i] = _buffer[i] + mt._buffer[i];
            }
            return sumMatrix;
        }
        std::cout << "ERROR SUM MATRIX" << std::endl;
    }

    /*Destructor*/
    ~MatrixTemplate(){
        delete[] _buffer;
    }

    /*Getters and setters*/
    int getRows() const { return _rows; }
    int getColumns() const { return _columns; }

private:
    int _rows, _columns;
    T* _buffer;

    void copier(const MatrixTemplate& mt){
        _rows = mt._rows;
        _columns = mt._columns;
        _buffer = new T[_rows * _columns];
        for(int i = 0; i <_rows*_columns; i++)
            _buffer[i] = mt._buffer[i];
    }

};

#endif //MATRIXABSFACTORY_MATRIXTEMPLATE_H
