#include <cstdlib>

class Matrix {
    class Row {
         int size;
        double *row;

    public:
        Row(double *row, int size) : row(row), size(size) {}

        double &operator[]( int columnNumber);
    };

public:
    int rowCount;
    int columnCount;
    double **matrix = nullptr;

    Matrix(int numberOfRows = 2, int numberOfColumns = 2);

    void saveMemory();

    bool canBeAddedOrSubtracted(Matrix *matrix);

    bool canBeMultiplied(Matrix *matrix);

    int getRowSize();

    int getColumnSize();

    void showElement(int row, int column);

    void editElement(int row, int column, float value);

    void printMatrix();

    void fillMatrix(float startValue=1);

    void copyValues(Matrix *matrix);

    Matrix *operator+(Matrix *matrix);

    Matrix *operator-(Matrix *matrix);

    Matrix *operator*(float number);

    Matrix *operator*(Matrix *matrix);

    inline void operator+=(Matrix *matrix);

    inline void operator-=(Matrix *matrix);

    inline void operator*=(Matrix *matrix);

    inline void operator*=(double number);

    Row &operator[](int rowNumber);
};


