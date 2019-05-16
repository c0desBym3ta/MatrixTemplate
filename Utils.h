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

void Utils::matrixInfo(){
    system("clear");
    std::cout << "\tPOSSIBLE MATRIX SELECTION" << std::endl;
    std::cout << "\t#########################" << std::endl;
    std::cout << "1) Row Matrix\n2) Columns Matrix\n3) Square Matrix\n4) Rectangular Matrix" << std::endl;
    line();
}
void Utils::fillMatrix() {
    std::cout << "\n\tFILL THE MATRIX" << std::endl;
    std::cout << "\t################" << std::endl;
    std::cout << "0) Zero values Matrix\n1) Random fill matrix.\n2) Manual fill matrix.\n3) Order Incremented Matrix." << std::endl;
}
void Utils::optionsScreen() {
    std::cout <<"\n\tAVAILABLE MATRIX OPERATIONS" << std::endl;
    std::cout << "\t###########################" << std::endl;
    std::cout << "0) Create Another Matrix." << std::endl;
    std::cout << "1) Show available matrix.\n2) Multiply Matrix.\n3) Multiply Matrix by Number." << std::endl;
    std::cout << "4) Edit Value Matrix.\n5) Divide Matrix by Number.\n6) Adding Matrix.\n7) Subtracting Matrix." << std::endl;
    std::cout << "8) Select Row of the Matrix.\n9) Select Column of the Matrix.\n10) Reduce triangular Matrix" << std::endl;
    std::cout << "99) Exit from the program." << std::endl;
}
void Utils::line(){
    std::cout << std::endl;
}
void Utils::clearScreen(){
    line();
    std::cout << "\nPress any key to continue..." << std::endl;
    std::cin.ignore().get();
    system("clear");
}
void Utils::readMatrix(int &rows, int &columns, std::string mName) {
    std::cout <<"\nEnter " << mName << " matrix rows: "; std::cin >> rows;
    std::cout << "Enter " <<  mName << " matrix columns: "; std::cin >> columns;
}
void Utils::readMatrix(int &rows, int &columns) {
    std::cout <<"\nEnter matrix rows: "; std::cin >> rows;
    std::cout << "Enter matrix columns: "; std::cin >> columns;
}

#endif //MATRIXABSFACTORY_UTILS_H
