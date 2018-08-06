#include "headers.h"
#include "MatrixTemplate.h"

int main() {
    MatrixTemplate<int> matrixTemplate(3,3);
    std::cout << "\tORIGINAL MATRIX" << std::endl;
    matrixTemplate.printMatrix(matrixTemplate);
    std::cout << std::endl;

    MatrixTemplate<int> testMatrixTemplate = matrixTemplate;
    std::cout << "\tTEST MATRIX TEMPLATE" << std::endl;
    testMatrixTemplate.printMatrix(testMatrixTemplate);
    std::cout << std::endl;

    MatrixTemplate<int> nonQuadMarix(1,3);
    std::cout << "\tNON QUAD MATRIX" << std::endl;
    nonQuadMarix.printMatrix();
    std::cout << std::endl;



    return 0;
}