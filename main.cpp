#include "headers.h"
//#include "MatrixTemplate.h"
#include "MatrixTemplate.cpp"

int main() {
    MatrixTemplate<int> matrixTemplate(3,3);
    std::cout << "\tORIGINAL MATRIX" << std::endl;
    matrixTemplate.printMatrix(matrixTemplate);
    std::cout << std::endl;

	MatrixTemplate<int> cMatrix = matrixTemplate.getTranspose();

	if(matrixTemplate != cMatrix)
		std::cout << "OK" << std::endl;

    return 0;
}
