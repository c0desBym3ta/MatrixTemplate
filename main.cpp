#include "headers.h"
#include "MatrixTemplate.h"
#include "MatrixFactory.h"
#include "MatrixFactoryType.h"
#include "Utils.h"
#include "MatrixUtils.h"
#include "SquareMatrix.h"


int intMatrix();
void floatMatrix();

int main(int argc, char **argv){
    std::string mType;
    std::cout << "Enter matrix type (int, float, double): "; std::cin >> mType;

    if(mType.compare("int") == 0)
        intMatrix();
    else if(mType.compare("float") == 0)
        floatMatrix();

    return 0;

}

int intMatrix(){
    Utils utils;
    int rows,columns;
    int count = 1;
    std::string mName, anws;
    MatrixUtils<int> matrixUtils;

    std::list<MatrixTemplate<int>*> listOfMatrix;
    MatrixFactory<int>* matrixFactory = new MatrixFactoryType<int>();

    utils.matrixInfo();

    anotherMatrix:
    std::cout <<"Enter number of rows: "; std::cin >> rows;
    std::cout << "Enter number of columns: "; std::cin >> columns;
    std::cout << "Enter matrix name: "; std::cin >> mName;
    std::cout << std::endl;

    MatrixTemplate<int>* autoGenerated = new SquareMatrix<int>(3,3);

    utils.clearScreen();
    utils.fillMatrix();
    int choice;
    std::cout << "\n\tEnter your choice: "; std::cin >> choice;
    if(choice == 0){
        utils.line();
        MatrixTemplate<int>* zeroMatrix = matrixFactory->selectMatrixType(rows,columns);
        zeroMatrix->setMatrixName("ZERO GENERATED");
        std::cout << "\nMatrix will be now initialized with 0..." << std::endl;
        zeroMatrix->matrixOfZeros();
        zeroMatrix->printMatrix();
        std::cout << "\nInsert to matrix list (yes,no): "; std::cin >> anws;
        if(anws.compare("yes") == 0){
            zeroMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(zeroMatrix);
        }
    }else if(choice == 1){
        utils.line();
        MatrixTemplate<int>* randomMatrix = matrixFactory->selectMatrixType(rows,columns);
        randomMatrix->setMatrixName("RANDOM GENERATED");
        std::cout << "\nMatrix will be now filled with random values..." << std::endl;
        randomMatrix->randomMatrix();
        randomMatrix->printMatrix();
        std::cout << "\nInsert to matrix list (yes,no): "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            randomMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(randomMatrix);
        }
    }else if(choice == 2){
        utils.line();
        MatrixTemplate<int>* manualMatrix = matrixFactory->selectMatrixType(rows,columns);
        manualMatrix->setMatrixName(mName);
        manualMatrix->manualInsertValues();
        std::cout << "\nInserting your values to the matrix..." << std::endl;
        manualMatrix->printMatrix();
        std::cout << "\nInsert to matrix list (yes,no): "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            manualMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(manualMatrix);
        }
    }else if(choice == 3){
        utils.line();
        MatrixTemplate<int>* seqMatrix = matrixFactory->selectMatrixType(rows,columns);
        seqMatrix->setMatrixName("SEQUENCE");
        std::cout << "\nInserting values of matrix in sequence..." << std::endl;
        seqMatrix->sequenceMatrix();
        seqMatrix->printMatrix();
        std::cout << "\nInsert to matrix list (yes,no): "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            seqMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(seqMatrix);
        }
    }else{
        std::cout << "\nDefault selection option" << std::endl;
    }


    int opt;
    utils.clearScreen();
    optionsScreen:
    utils.optionsScreen();
    std::cout << "\n\tEnter your choice: "; std::cin >> opt;
    if(opt == 0){
        utils.clearScreen();
        goto anotherMatrix;
    }else if(opt == 1){
        matrixUtils.printListOfMatrix(listOfMatrix);
        utils.clearScreen();
        goto optionsScreen;
    }else if(opt == 2) {
        utils.readMatrix(rows,columns,"first matrix");
        MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.readMatrix(rows,columns,"second matrix");
        MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(rows,columns);
        secondMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.clearScreen();
        std::cout << "Multiplying the following matrix...\n" << std::endl;
        firstMatrix->printMatrix("FIRST MATRIX");
        secondMatrix->printMatrix("SECOND MATRIX");
        utils.line();

        MatrixTemplate<int>* prodMatrix = matrixFactory->selectMatrixType(1,1);
        prodMatrix->setMatrixName("PRODUCT RESULT");
        *prodMatrix = (*firstMatrix)*(*secondMatrix);
        prodMatrix->printMatrix(prodMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            prodMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(prodMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 3){
        int mNum;
        utils.readMatrix(rows,columns);
        MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        std::cout << "\nSelect a number to multiply the following matrix." << std::endl;
        firstMatrix->printMatrix();
        std::cout << "\n\tEnter your choice: "; std::cin >> mNum;
        utils.clearScreen();

        std::cout << "We are multiplying the matrix with the number " << mNum << "." << std::endl;
        std::cout << "Processing the request..." << std::endl;
        MatrixTemplate<int>* prodNumMatrix = matrixFactory->selectMatrixType(1,1);
        *prodNumMatrix = (*firstMatrix)*mNum;
        prodNumMatrix->setMatrixName("MULTIPLIED MATRIX");
        prodNumMatrix->printMatrix(prodNumMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            prodNumMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(prodNumMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }
        else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 4){
        int value, tRow, tCol;
        utils.clearScreen();
        std::cout << "\nSelect value of the following matrix to modify." << std::endl;
        autoGenerated->printMatrix();
        utils.line();
        std::cout << "\nEnter the new value to insert in the matrix: "; std::cin >> value;
        std::cout << "Enter row number of element to modify: "; std::cin >> tRow;
        std::cout << "Enter columns number of elemenet to modify: "; std::cin >> tCol;
        autoGenerated->modifyElement(tRow,tCol,value);
        std::cout << "\nWe are now processing the request..." << std::endl;
        utils.line();
        autoGenerated->setMatrixName("CHANGED VALUE");
        autoGenerated->printMatrix();
        std::cout << "\n\nDo you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0){
            autoGenerated->setMatrixId(count);
            count++;
            listOfMatrix.push_back(autoGenerated);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 5){
        int dNum;
        std::cout <<"\nEnter first matrix rows: "; std::cin >> rows;
        std::cout << "Enter first matrix columns: "; std::cin >> columns;
        MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        std::cout << "\nSelect a number to divide the following matrix." << std::endl;
        firstMatrix->printMatrix();
        std::cout << "\n\tEnter your choice: "; std::cin >> dNum;
        utils.clearScreen();

        std::cout << "We are dividing the matrix with the number " << dNum << "." << std::endl;
        std::cout << "Processing the request..." << std::endl;
        MatrixTemplate<int>* divMatrix = matrixFactory->selectMatrixType(1,1);
        *divMatrix = (*firstMatrix)/dNum;
        divMatrix->setMatrixName("DIVIDED MATRIX");
        divMatrix->printMatrix(divMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            divMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(divMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }
        else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 6){
        utils.readMatrix(rows,columns,"first matrix");
        MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.readMatrix(rows,columns,"second matrix");
        MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(rows,columns);
        secondMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.clearScreen();
        std::cout << "Adding the following matrix...\n" << std::endl;
        firstMatrix->printMatrix("FIRST MATRIX");
        secondMatrix->printMatrix("SECOND MATRIX");
        utils.line();

        MatrixTemplate<int>* addMatrix = matrixFactory->selectMatrixType(1,1);
        addMatrix->setMatrixName("ADDITION RESULT");
        *addMatrix = (*firstMatrix)+(*secondMatrix);
        addMatrix->printMatrix(addMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            addMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(addMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 7){
        utils.readMatrix(rows,columns,"first matrix");
        MatrixTemplate<int>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.readMatrix(rows,columns,"second matrix");
        MatrixTemplate<int>* secondMatrix = matrixFactory->selectMatrixType(rows,columns);
        secondMatrix->manualInsertValues();
        std::cout << std::endl;
        utils.clearScreen();

        std::cout << "Subtracting the following matrix...\n" << std::endl;
        firstMatrix->printMatrix("FIRST MATRIX");
        secondMatrix->printMatrix("SECOND MATRIX");
        utils.line();

        MatrixTemplate<int>* subMatrix = matrixFactory->selectMatrixType(1,1);
        secondMatrix->setMatrixName("SUBTRACTED RESULT");
        *subMatrix = (*firstMatrix)-(*secondMatrix);
        subMatrix->printMatrix(subMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            subMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(subMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 8){
        int rNum;
        std::cout << "\nWhich row do you want to select from the following matrix.\n" << std::endl;
        autoGenerated->printMatrix();
        std::cout << std::endl;
        std::cout << "\n\tEnter your choice: "; std::cin >> rNum;
        std::cout << "The row number " << rNum << " is now selected." << std::endl;
        std::cout << "Processing the request..." << std::endl;
        MatrixTemplate<int>* rowMatrix = matrixFactory->selectMatrixType(1,1);
        *rowMatrix = (*autoGenerated).selectRow(rNum);
        rowMatrix->setMatrixName("ROW");
        rowMatrix->printMatrix(rowMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            rowMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(rowMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 9){
        int cNum;
        std::cout << "\nWhich columns do you want to select from the following matrix.\n" << std::endl;
        autoGenerated->printMatrix();
        std::cout << std::endl;
        std::cout << "\n\tEnter your choice: "; std::cin >> cNum;
        std::cout << "The column number " << cNum << " is now selected." << std::endl;
        std::cout << "Processing the request..." << std::endl;
        MatrixTemplate<int>* columnMatrix = matrixFactory->selectMatrixType(1,1);
        *columnMatrix = (*autoGenerated).selectColumn(cNum);
        columnMatrix->setMatrixName("COLUMN");
        columnMatrix->printMatrix(columnMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0){
            columnMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(columnMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else {
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 10){
        utils.clearScreen();
        std::cout << "\nUnder construction." << std::endl;
        utils.clearScreen();
        goto optionsScreen;
    }else if(opt == 99){
        matrixUtils.deleteList(listOfMatrix);
        std::cout << "\nNow exiting form the program...";
        utils.clearScreen();
        return 0;
    }else{
        std::cout << "Under construction." << std::endl;
        utils.clearScreen();
        goto optionsScreen;
    }
}
void floatMatrix(){
    Utils utils;
    int rows,columns;
    int count = 1;
    std::string mName, anws;
    MatrixUtils<float> matrixUtils;

    std::list<MatrixTemplate<float>*> listOfMatrix;
    MatrixFactory<float>* matrixFactory = new MatrixFactoryType<float>();

    utils.matrixInfo();

    anotherMatrix:
    std::cout <<"Enter number of rows: "; std::cin >> rows;
    std::cout << "Enter number of columns: "; std::cin >> columns;
    std::cout << "Enter matrix name: "; std::cin >> mName; /*std::getline(std::cin, mName);*/
    std::cout << std::endl;

    MatrixTemplate<float>* autoGenerated = new SquareMatrix<float>(3,3);

    utils.clearScreen();
    utils.fillMatrix();
    int choice;
    std::cout << "\n\tEnter your choice: "; std::cin >> choice;
    if(choice == 0){
        utils.line();
        MatrixTemplate<float>* zeroMatrix = matrixFactory->selectMatrixType(rows,columns);
        zeroMatrix->setMatrixName("ZERO GENERATED");
        std::cout << "\nMatrix will be now initialized with 0..." << std::endl;
        zeroMatrix->matrixOfZeros();
        zeroMatrix->printMatrix();
        std::cout << "\nInsert to matrix list (yes,no): "; std::cin >> anws;
        if(anws.compare("yes") == 0){
            zeroMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(zeroMatrix);
        }
    }else if(choice == 1){
        utils.line();
        MatrixTemplate<float>* randomMatrix = matrixFactory->selectMatrixType(rows,columns);
        randomMatrix->setMatrixName("RANDOM GENERATED");
        std::cout << "\nMatrix will be now filled with random values..." << std::endl;
        randomMatrix->randomMatrix();
        randomMatrix->printMatrix();
        std::cout << "\nInsert to matrix list (yes,no): "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            randomMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(randomMatrix);
        }
    }else if(choice == 2){
        utils.line();
        MatrixTemplate<float>* manualMatrix = matrixFactory->selectMatrixType(rows,columns);
        manualMatrix->setMatrixName(mName);
        manualMatrix->manualInsertValues();
        std::cout << "\nInserting your values to the matrix..." << std::endl;
        manualMatrix->printMatrix();
        std::cout << "\nInsert to matrix list (yes,no): "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            manualMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(manualMatrix);
        }
    }else if(choice == 3){
        utils.line();
        MatrixTemplate<float>* seqMatrix = matrixFactory->selectMatrixType(rows,columns);
        seqMatrix->setMatrixName("SEQUENCE");
        std::cout << "\nInserting values of matrix in sequence..." << std::endl;
        seqMatrix->sequenceMatrix();
        seqMatrix->printMatrix();
        std::cout << "\nInsert to matrix list (yes,no): "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            seqMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(seqMatrix);
        }
    }else{
        std::cout << "\nDefault selection option" << std::endl;
    }


    int opt;
    utils.clearScreen();
    optionsScreen:
    utils.optionsScreen();
    std::cout << "\n\tEnter your choice: "; std::cin >> opt;
    if(opt == 0){
        utils.clearScreen();
        goto anotherMatrix;
    }else if(opt == 1){
        matrixUtils.printListOfMatrix(listOfMatrix);
        utils.clearScreen();
        goto optionsScreen;
    }else if(opt == 2) {
        utils.readMatrix(rows,columns,"first matrix");
        MatrixTemplate<float>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.readMatrix(rows,columns,"second matrix");
        MatrixTemplate<float>* secondMatrix = matrixFactory->selectMatrixType(rows,columns);
        secondMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.clearScreen();
        std::cout << "Multiplying the following matrix...\n" << std::endl;
        firstMatrix->printMatrix("FIRST MATRIX");
        secondMatrix->printMatrix("SECOND MATRIX");
        utils.line();

        MatrixTemplate<float>* prodMatrix = matrixFactory->selectMatrixType(1,1);
        prodMatrix->setMatrixName("PRODUCT RESULT");
        *prodMatrix = (*firstMatrix)*(*secondMatrix);
        prodMatrix->printMatrix(prodMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            prodMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(prodMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 3){
        int mNum;
        utils.readMatrix(rows,columns);
        MatrixTemplate<float>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        std::cout << "\nSelect a number to multiply the following matrix." << std::endl;
        firstMatrix->printMatrix();
        std::cout << "\n\tEnter your choice: "; std::cin >> mNum;
        utils.clearScreen();

        std::cout << "We are multiplying the matrix with the number " << mNum << "." << std::endl;
        std::cout << "Processing the request..." << std::endl;
        MatrixTemplate<float>* prodNumMatrix = matrixFactory->selectMatrixType(1,1);
        *prodNumMatrix = (*firstMatrix)*mNum;
        prodNumMatrix->setMatrixName("MULTIPLIED MATRIX");
        prodNumMatrix->printMatrix(prodNumMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            prodNumMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(prodNumMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }
        else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 4){
        int value, tRow, tCol;
        utils.clearScreen();
        std::cout << "\nSelect value of the following matrix to modify." << std::endl;
        autoGenerated->printMatrix();
        utils.line();
        std::cout << "\nEnter the new value to insert in the matrix: "; std::cin >> value;
        std::cout << "Enter row number of element to modify: "; std::cin >> tRow;
        std::cout << "Enter columns number of elemenet to modify: "; std::cin >> tCol;
        autoGenerated->modifyElement(tRow,tCol,value);
        std::cout << "\nWe are now processing the request..." << std::endl;
        utils.line();
        autoGenerated->setMatrixName("CHANGED VALUE");
        autoGenerated->printMatrix();
        std::cout << "\n\nDo you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes")){
            autoGenerated->setMatrixId(count);
            count++;
            listOfMatrix.push_back(autoGenerated);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 5){
        int dNum;
        std::cout <<"\nEnter first matrix rows: "; std::cin >> rows;
        std::cout << "Enter first matrix columns: "; std::cin >> columns;
        MatrixTemplate<float>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        std::cout << "\nSelect a number to divide the following matrix." << std::endl;
        firstMatrix->printMatrix();
        std::cout << "\n\tEnter your choice: "; std::cin >> dNum;
        utils.clearScreen();

        std::cout << "We are dividing the matrix with the number " << dNum << "." << std::endl;
        std::cout << "Processing the request..." << std::endl;
        MatrixTemplate<float>* divMatrix = matrixFactory->selectMatrixType(1,1);
        *divMatrix = (*firstMatrix)/dNum;
        divMatrix->setMatrixName("DIVIDED MATRIX");
        divMatrix->printMatrix(divMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            divMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(divMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }
        else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 6){
        utils.readMatrix(rows,columns,"first matrix");
        MatrixTemplate<float>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.readMatrix(rows,columns,"second matrix");
        MatrixTemplate<float>* secondMatrix = matrixFactory->selectMatrixType(rows,columns);
        secondMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.clearScreen();
        std::cout << "Multiplying the following matrix...\n" << std::endl;
        firstMatrix->printMatrix("FIRST MATRIX");
        secondMatrix->printMatrix("SECOND MATRIX");
        utils.line();

        MatrixTemplate<float>* addMatrix = matrixFactory->selectMatrixType(1,1);
        addMatrix->setMatrixName("ADDITION RESULT");
        *addMatrix = (*firstMatrix)+(*secondMatrix);
        addMatrix->printMatrix(addMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            addMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(addMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 7){
        utils.readMatrix(rows,columns,"first matrix");
        MatrixTemplate<float>* firstMatrix = matrixFactory->selectMatrixType(rows,columns);
        firstMatrix->manualInsertValues();
        std::cout << std::endl;

        utils.readMatrix(rows,columns,"second matrix");
        MatrixTemplate<float>* secondMatrix = matrixFactory->selectMatrixType(rows,columns);
        secondMatrix->manualInsertValues();
        std::cout << std::endl;
        utils.clearScreen();

        std::cout << "Subtracting the following matrix...\n" << std::endl;
        firstMatrix->printMatrix("FIRST MATRIX");
        secondMatrix->printMatrix("SECOND MATRIX");
        utils.line();

        MatrixTemplate<float>* subMatrix = matrixFactory->selectMatrixType(1,1);
        secondMatrix->setMatrixName("SUBTRACTED RESULT");
        *subMatrix = (*firstMatrix)-(*secondMatrix);
        subMatrix->printMatrix(subMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            subMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(subMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 8){
        int rNum;
        std::cout << "\nWhich row do you want to select from the following matrix.\n" << std::endl;
        autoGenerated->printMatrix();
        std::cout << std::endl;
        std::cout << "\n\tEnter your choice: "; std::cin >> rNum;
        std::cout << "The row number " << rNum << " is now selected." << std::endl;
        std::cout << "Processing the request..." << std::endl;
        MatrixTemplate<float>* rowMatrix = matrixFactory->selectMatrixType(1,1);
        *rowMatrix = (*autoGenerated).selectRow(rNum);
        rowMatrix->setMatrixName("ROW");
        rowMatrix->printMatrix(rowMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0) {
            rowMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(rowMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else{
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 9){
        int cNum;
        std::cout << "\nWhich columns do you want to select from the following matrix.\n" << std::endl;
        autoGenerated->printMatrix();
        std::cout << std::endl;
        std::cout << "\n\tEnter your choice: "; std::cin >> cNum;
        std::cout << "The column number " << cNum << " is now selected." << std::endl;
        std::cout << "Processing the request..." << std::endl;
        MatrixTemplate<float>* columnMatrix = matrixFactory->selectMatrixType(1,1);
        *columnMatrix = (*autoGenerated).selectColumn(cNum);
        columnMatrix->setMatrixName("COLUMN");
        columnMatrix->printMatrix(columnMatrix->getMatrixName());
        utils.line();
        std::cout << "Do you want to save this matrix: "; std::cin >> anws;
        if(anws.compare("yes") == 0){
            columnMatrix->setMatrixId(count);
            count++;
            listOfMatrix.push_back(columnMatrix);
            std::cout << "\n\nThe matrix is now saved to your list!" << std::endl;
            utils.clearScreen();
            goto optionsScreen;
        }else {
            utils.clearScreen();
            goto optionsScreen;
        }
    }else if(opt == 10){
        std::cout << "\nUnder construction..." << std::endl;
        utils.clearScreen();
        goto optionsScreen;
    }else if(opt == 99){
        std::cout << "\nNow exiting form the program...";
        utils.clearScreen();

    }else{
        std::cout << "Under construction." << std::endl;
        utils.clearScreen();
        goto optionsScreen;
    }

}

