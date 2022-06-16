#include <iostream>
#include "matrix.h"

using namespace std;

int main() {

    Matrix* firstMatrix = new Matrix(4, 4);

    cout<<"First Matrix: \n";

    firstMatrix->fillMatrix();

    firstMatrix->printMatrix();

    Matrix* secondMatrix = new Matrix(3, 4);

    cout<<"Second Matrix: \n";

    secondMatrix->fillMatrix();
    secondMatrix->printMatrix();

    cout<<"Third Matrix: \n";

    auto thirdMatrix = new Matrix(4, 4);

    thirdMatrix->fillMatrix(3);
    thirdMatrix->printMatrix();

    cout<<"Multiplication first Matrix by third\n";

    Matrix* multiplicationByMatrix = (((*firstMatrix) * thirdMatrix));
    multiplicationByMatrix->printMatrix();

    cout<<"Multiplication first Matrix by 5\n";

    Matrix* multiplicationByNumber = (((*firstMatrix) * 5));
    multiplicationByNumber->printMatrix();

    cout<<"Additional Matrix first and third\n";
    Matrix* additional = (((*firstMatrix) + thirdMatrix));

    additional->printMatrix();

    cout<<"Substract Matrix first and second\n";

    Matrix* substract = ((*firstMatrix) - thirdMatrix);

    substract->printMatrix();

    while(true)
    {
    double choose1, choose2;
    float value;
    string choose;
    int operation;
    Matrix *element;

    cout<<"\n===============================================================================================\n\n";
    cout<<"select the matrix, you want to work on: \n 1.First \n 2.Second \n 3.Third\n";
    cin>> choose;
    if(choose == "1" || choose == "First" || choose == "first"){
        element = firstMatrix;
        element->printMatrix();
    }
    else if(choose == "2" || choose == "Second" || choose == "second"){
        element = secondMatrix;
        element->printMatrix();
    }
    else{
        element = thirdMatrix;
        element->printMatrix();
    }
    cout<<"\nSend me, what do you want to do?: \n 1.Edit \n 2.Show\n";
    cin>>operation;
    switch (operation) {
        case 1:
            cout<<"Give me first matrix's row element who You want to edit: ";
            cin>>choose1;
            cout<<"Give me first matrix's column element who You want to edit: ";
            cin>>choose2;
            cout<<"Give value, what you want incorrect: ";
            cin>>value;
            element->editElement(choose1, choose2, value);
            element->printMatrix();
            break;
        case 2:
            cout<<"Give me first matrix's row element who You want see:";
            cin>>choose1;
            cout<<"Give me first matrix's column element who You want see:";
            cin>>choose2;
            element->showElement(choose1, choose2);
            break;

    }

    }
    return 0;
}
