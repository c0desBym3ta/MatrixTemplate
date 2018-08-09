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
    ~MatrixTemplate(); /*tested*/

    /*Matrix Operations*/
    virtual MatrixTemplate getTranspose() const;/*tested*/
    virtual MatrixTemplate<T> selectRow(int rowNum);/*tested*/
    virtual MatrixTemplate<T> selectColumn(int colNum);/*tested*/
    virtual MatrixTemplate<T> swapRows(int i, int j); /*TODO*/
    virtual T elementPosition(int rowPos, int colPos) const; /*tested*/
    virtual void modifyElement(int rowNum, int colNum, const T& newValue); /*tested*/
    virtual void manualInsertValues(MatrixTemplate& newMatrixTemplate); /*tested*/
    virtual void matrixOfZeros(); /*tested*/
    virtual void randomMatrix(); /*tested*/
    virtual void sequenceMatrix(); /*tested*/
    virtual void manualInsertValues(); /*tested*/
    virtual void printMatrix(MatrixTemplate& matrixTemplate); /*tested*/
    virtual void printMatrix(std::string matrixName); /*tested*/
    virtual void printMatrix(); /*tested*/

    /*Operator overloading*/
    virtual MatrixTemplate<T>& operator=(const MatrixTemplate<T>& mt);/*tested*/
    virtual MatrixTemplate<T> operator+(const MatrixTemplate<T>& mt);/*tested*/
    virtual MatrixTemplate<T> operator*(const MatrixTemplate<T>& mt);/*tested*/
    virtual MatrixTemplate<T> operator*(const T& num);/*tested*/
    virtual MatrixTemplate<T> operator/(const MatrixTemplate<T>& mt);/*tested*/
    virtual MatrixTemplate<T> operator/(const T& num); /*tested*/
    virtual MatrixTemplate<T> operator-(const MatrixTemplate<T>& mt);/*tested*/
    virtual MatrixTemplate<T> operator+=(const MatrixTemplate<T>& mt);/*tested*/
    virtual bool operator==(const MatrixTemplate<T>& mt) const;/*tested*/
    virtual bool operator!=(const MatrixTemplate<T>& mt) const;/*tested*/

    /*Getters and setters*/
    virtual int getRows() const ; /*tested*/
    virtual int getColumns() const ; /*tested*/
    virtual const std::string &getMatrixName() const;
    virtual void setMatrixName(const std::string &_matrixName);


protected:
    int _rows, _columns;
    T* _buffer;
    std::string _matrixName;

    void copier(const MatrixTemplate& mt);

};

#endif //MATRIXABSFACTORY_MATRIXTEMPLATE_H
