#ifndef MATRIX_H
#define MATRIX_H

struct Matrix {
    int** data;
    int n;
};

Matrix createMatrix(int size);
void inputSymmetricMatrix(Matrix& matrix);
Matrix generateNewMatrix(const Matrix& matrix);
void printMatrix(const Matrix& matrix);
void destroyMatrix(Matrix& matrix);

#endif
//структура матрицы структкура строки