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
    MatrixTemplate<T> selectRow(int rowNum);/*tested*/
    MatrixTemplate<T> selectColumn(int colNum);/*tested*/
    T elementPosition(int rowPos, int colPos) const; /*tested*/
    void modifyElement(int rowNum, int colNum, const T& newValue); /*tested*/
    void printMatrix(MatrixTemplate& matrixTemplate); /*tested*/
    void printMatrix(); /*tested*/

    /*Operator overloading*/
    MatrixTemplate<T>& operator=(const MatrixTemplate<T>& mt);
    MatrixTemplate<T> operator+(const MatrixTemplate<T>& mt);/*tested*/
    MatrixTemplate<T> operator*(const MatrixTemplate<T>& mt);/*tested*/
    MatrixTemplate<T> operator*(const T& num);/*tested*/
    MatrixTemplate<T> operator-(const MatrixTemplate<T>& mt);/*tested*/
    MatrixTemplate<T> operator/(const MatrixTemplate<T>& mt);/*tested*/
    MatrixTemplate<T> operator+=(const MatrixTemplate<T>& mt);/*tested*/
    bool operator==(const MatrixTemplate<T>& mt) const;/*tested*/
    bool operator!=(const MatrixTemplate<T> &mt) const;/*tested*/

    /*Getters and setters*/
    int getRows() const ; /*tested*/
    int getColumns() const ; /*tested*/

private:
    int _rows, _columns;
    T* _buffer;

    void copier(const MatrixTemplate& mt);

};

#endif //MATRIXABSFACTORY_MATRIXTEMPLATE_H
