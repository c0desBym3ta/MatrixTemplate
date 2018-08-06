#include "headers.h"
#include "MatrixTemplate.h"

int main() {
    MatrixTemplate<int> matrixTemplate(3,3);
    std::cout << "ORIGINAL MATRIX " << std::endl;
    matrixTemplate.printMatrix(matrixTemplate);

    std::cout << std::endl;

    MatrixTemplate<int> trasposeMatrix = matrixTemplate.getTranspose();
    std::cout << "TRANSPOSE MATRIX " << std::endl;
    trasposeMatrix.printMatrix(trasposeMatrix);


    return 0;
}