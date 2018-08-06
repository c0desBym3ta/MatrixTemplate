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
                std::cout << "[" << _buffer[j + i * _columns] << "]";
            std::cout << std::endl;
        }

    }






    /*Operator overloading*/
    bool operator!=(const MatrixTemplate& mt);
    bool operator==(const MatrixTemplate& mt);

    /*Destructor*/
    ~MatrixTemplate(){
        delete[] _buffer;
    }
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
