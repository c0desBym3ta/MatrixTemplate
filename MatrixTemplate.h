//
// Created by m3taprog on 06/08/18.
//

#ifndef MATRIXABSFACTORY_MATRIXTEMPLATE_H
#define MATRIXABSFACTORY_MATRIXTEMPLATE_H

#include "headers.h"

template <class T>
class MatrixTemplate {
public:
    /*Constructors and Destructor.*/
    MatrixTemplate(int r, int c) ; /*tested*/
    MatrixTemplate(const MatrixTemplate& mt);/*tested*/
    ~MatrixTemplate();

    /*Matrix Operations*/
    MatrixTemplate getTranspose() const;/*tested*/
    MatrixTemplate<T> selectRow(int rowNum);
    MatrixTemplate<T> selectColumn(int colNum);
    T elementPosition(int rowPos, int colPos) const;
    void printMatrix(MatrixTemplate& matrixTemplate);
    void printMatrix();

    /*Operator overloading*/
    MatrixTemplate<T>& operator=(const MatrixTemplate<T>& mt);
    MatrixTemplate<T> operator+(const MatrixTemplate<T>& mt);
    MatrixTemplate<T> operator*(const MatrixTemplate<T>& mt);
    MatrixTemplate<T> operator*(const T& num);
    MatrixTemplate<T> operator-(const MatrixTemplate<T>& mt);
    MatrixTemplate<T> operator/(const MatrixTemplate<T>& mt);
    MatrixTemplate<T> operator+=(const MatrixTemplate<T>& mt);
    bool operator==(const MatrixTemplate<T>& mt) const;
    bool operator!=(const MatrixTemplate<T>& mt) const;

    /*Getters and setters*/
    int getRows() const ;
    int getColumns() const ;

private:
    int _rows, _columns;
    T* _buffer;

    void copier(const MatrixTemplate& mt);

};

#endif //MATRIXABSFACTORY_MATRIXTEMPLATE_H
