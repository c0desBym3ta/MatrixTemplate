#include "headers.h"
#include "MatrixTemplate.h"

int main() {
    MatrixTemplate<int> matrixTemplate(3,3);
    std::cout << "\tORIGINAL MATRIX " << std::endl;
    matrixTemplate.printMatrix(matrixTemplate);
    std::cout << std::endl;

    MatrixTemplate<int> testMatrixTemplate = matrixTemplate;
    std::cout << "\tTEST MATRIX TEMPLATE" << std::endl;
    testMatrixTemplate.printMatrix(testMatrixTemplate);
    std::cout << std::endl;

    MatrixTemplate<int> transposeMatrix = matrixTemplate.getTranspose();
    std::cout << "\tTRANSPOSE MATRIX" << std::endl;
    transposeMatrix.printMatrix();
    std::cout << std::endl;

    MatrixTemplate<int> sumMatrix = testMatrixTemplate + transposeMatrix;
    std::cout << "\tSUM MATRIX RESULT" << std::endl;
    sumMatrix.printMatrix();
    std::cout << std::endl;





    return 0;
}