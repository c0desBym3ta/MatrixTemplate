//
// Created by m3taprog on 08/08/18.
//

#include "Utils.h"

void Utils::matrixInfo() {
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
    std::cout << "0) Show available matrix.\n1) Multiply Matrix.\n2) Multiply Matrix by Number." << std::endl;
    std::cout << "3) Divide Matrix.\n4) Divide Matrix by Number.\n5) Adding Matrix.\n6) Subtracting Matrix." << std::endl;
    std::cout << "7) Select Row of the Matrix.\n8) Select Columna of the Matrix." << std::endl;
    std::cout << "99) Exit from the program." << std::endl;
}

void Utils::line() {
    std::cout << std::endl;
}

void Utils::clearScreen(){
    line();
    std::cout << "\nPress any key to continue..." << std::endl;
    std::cin.ignore().get();
    system("clear");
}