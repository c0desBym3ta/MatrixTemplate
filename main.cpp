#include "headers.h"
#include "MatrixTemplate.cpp"

int main() {
    MatrixTemplate<float> matrixTemplate(3,3);
    std::cout << "\tORIGINAL MATRIX" << std::endl;
    matrixTemplate.printMatrix(matrixTemplate);
    std::cout << std::endl;

	matrixTemplate.modifyElement(2,2,3.5);
	matrixTemplate.printMatrix();

    return 0;
}
