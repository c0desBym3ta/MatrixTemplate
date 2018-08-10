//
// Created by m3taprog on 08/08/18.
//

#ifndef MATRIXABSFACTORY_UTILS_H
#define MATRIXABSFACTORY_UTILS_H

#include "headers.h"
#include "MatrixTemplate.h"

class Utils {
public:
    void matrixInfo();
    void fillMatrix();
    void optionsScreen();
    void line();
    void clearScreen();
    void readMatrix(int& rows, int& columns, std::string mName);
    void readMatrix(int& rows, int& columns);
};


#endif //MATRIXABSFACTORY_UTILS_H
