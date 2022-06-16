#include <cstdlib>
#include <iostream>
#include "matrix.h"

using namespace std;

Matrix::Row &Matrix::operator[](int rowNumber) {
    if (rowNumber < 1 || rowNumber > this->getRowSize()) {
        cout<< ("Row number out of range.");
        system("pause");
    }
    Row *row = new Row(*(this->matrix + rowNumber), this->getColumnSize());
    return *row;
}

Matrix::Matrix( int numberOfRows,  int numberOfColumns) : columnCount(
        numberOfColumns), rowCount(numberOfRows) {
    this->saveMemory();
}

void Matrix::printMatrix() {
    for (int r = 1; r <= this->getRowSize(); r += 1) {
        for (int c = 1; c <= this->getColumnSize(); c += 1) {
            cout <<"  "<< (*this)[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matrix::fillMatrix(float startValue) {
    for (int r = 1; r <= this->getRowSize(); r += 1) {
        for (int c = 1; c <= this->getColumnSize(); c += 1) {
            (*this)[r][c] = startValue * r + (startValue * c / 10);
        }
    }
}

int Matrix::getRowSize() {
    return this->rowCount;
}

int Matrix::getColumnSize() {
    return this->columnCount;
}

void Matrix::saveMemory() {
    this->matrix = static_cast<double **>(malloc(sizeof(double) * rowCount));
    for ( int r = 0; r < this->rowCount; r += 1) {
        this->matrix[r] = static_cast<double *>(malloc(sizeof(double) * this->columnCount));
    }
    for (int row = 0; row < this->rowCount; row += 1) {
            *(this->matrix + row) -= 1;
    }
    this->matrix -= 1;
}

bool Matrix::canBeAddedOrSubtracted(Matrix *matrix) {
    return this->getRowSize() == matrix->getRowSize() && this->getColumnSize() == matrix->getColumnSize();
}

bool Matrix::canBeMultiplied(Matrix *matrix) {
    return this->getColumnSize() == matrix->getRowSize();
}

void Matrix::showElement(int row, int column){
    cout<<this->matrix[row][column]<<endl;
};

void Matrix::editElement(int row, int column, float value) {
    this->matrix[row][column] = value;
    this->showElement(row, column);
}


Matrix *Matrix::operator+(Matrix *matrix) {
        if (!this->canBeAddedOrSubtracted(matrix)) {
            cout<< "You can ONLY add matrix the same size of rows and columns..";
            system("pause");
        }

        int newRowCount = this->getRowSize();
        int newColumnCount = this->getColumnSize();
        Matrix* newMatrix = new Matrix(newRowCount, newColumnCount);

        for (int r = 1; r <= newMatrix->getRowSize(); r += 1) {
            for (int c = 1; c <= newMatrix->getColumnSize(); c += 1) {
                (*newMatrix)[r][c] = (*this)[r][c] + (*matrix)[r][c];
            }
        }
        return newMatrix;
    }


Matrix *Matrix::operator-(Matrix *matrix) {
        if (!this->canBeAddedOrSubtracted(matrix)) {
            cout<<"You can ONLY substract matrix the same size of rows and columns.";
            system("pause");
        }
        int newRowCount = this->getRowSize();
        int newColumnCount = this->getColumnSize();
        Matrix* newMatrix = new Matrix(newRowCount, newColumnCount);

        for (int row = 1; row <= newMatrix->getRowSize(); row += 1) {
            for (int column = 1; column <= newMatrix->getColumnSize(); column += 1) {
                (*newMatrix)[row][column] = (*this)[row][column] - (*matrix)[row][column];
            }
        }
        return newMatrix;
}

//multiply by Matrix
Matrix *Matrix::operator*(Matrix *matrix) {
        if (!this->canBeMultiplied(matrix)) {
            cout<<("Multiply two matrix is possible if number of row first Matrix is equal number of column second matrix");
            system("pause");
        }
        int newRowCount = this->getRowSize();
        int newColumnCount = matrix->getColumnSize();
        Matrix* newMatrix = new Matrix(newRowCount, newColumnCount);

        for (int row = 1; row <= newMatrix->getRowSize(); row += 1) {
            for (int column = 1; column <= newMatrix->getColumnSize(); column += 1) {
                double value = 0;
                for (int pos = 1; pos < newRowCount; pos += 1) {
                    value += (*this)[row][pos] * (*matrix)[pos][column];
                }
                (*newMatrix)[row][column] = value;
            }
        }
        return newMatrix;
}

//multiply by number
Matrix *Matrix::operator*(float number) {
        int newRowCount = this->getRowSize();
        int newColumnCount = this->getColumnSize();
        Matrix* newMatrix = new Matrix(newRowCount, newColumnCount);

        for (int row = 1; row <= newMatrix->getRowSize(); row += 1) {
            for (int column = 1; column <= newMatrix->getColumnSize(); column += 1) {
                (*newMatrix)[row][column] = (*this)[row][column] * number;
            }
        }
        return newMatrix;
}

inline void Matrix::operator+=(Matrix *matrix) {
    Matrix* result = (*this) + matrix;
    this->copyValues(result);
    delete result;
}

inline void Matrix::operator-=(Matrix *matrix) {
    Matrix* result = (*this) - matrix;
    this->copyValues(result);
    delete result;
}

inline void Matrix::operator*=(Matrix *matrix) {
    Matrix* result = (*this) * matrix;;
    this->copyValues(result);
    delete result;

}

void Matrix::operator*=(double number) {
    Matrix* result = (*this) * number;
    this->copyValues(result);
    delete result;
}

void Matrix::copyValues(Matrix *matrix) {

    if (this->getRowSize() != matrix->getRowSize() || this->getColumnSize() != matrix->getColumnSize()) {
        cout<<("Cannot assign matrix of different dimensions.");
        system("pause");
    }

    for (int row = 1; row <= this->getRowSize(); row += 1) {
        for (int column = 1; column <= this->getColumnSize(); column += 1) {
            this[row][column] = matrix[row][column];
        }
    }
}


double &Matrix::Row::operator[]( int columnNumber) {
    if (columnNumber < 1 || columnNumber > size) {
        cout<<"Column is not exist.";
    }
    return *(row + columnNumber);
}



