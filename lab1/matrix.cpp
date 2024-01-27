#include "matrix.h"
#include <iostream>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

Matrix createMatrix(int size) {
    if (size == 0) {
        throw std::invalid_argument("The size of the matrix must be a positive number.");
    }
    Matrix matrix;
    matrix.n = size;
    matrix.data = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix.data[i] = new int[size];
    }

    return matrix;
}

void inputSymmetricMatrix(Matrix& matrix) {
    std::cout << "Enter elements for the symmetric matrix:\n";
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j <i+1; j++) {
            std::cout << "[" << i << "][" << j << "]: ";
            std::cin >> matrix.data[i][j];
            if (i != j) {
                matrix.data[j][i] = matrix.data[i][j];
            }
        }
    }
}

Matrix generateNewMatrix(const Matrix& matrix) { //Принимает константную ссылку на структуру в качестве параметра и возвращает новую структуру Matrix
    Matrix newMatrix = createMatrix(matrix.n);

    for (int i = 0; i < matrix.n; i++) {
        int sum = sumOfDigits(matrix.data[i][matrix.n - 1]);

        for (int j = 0; j < matrix.n; j++) {
            newMatrix.data[i][j] = (sumOfDigits(matrix.data[i][j]) == sum) ? matrix.data[i][j] : 0;
        }
    }

    return newMatrix;
}

void printMatrix(const Matrix& matrix) {
    std::cout << "Matrix:\n";
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.n; j++) {
            std::cout << matrix.data[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void destroyMatrix(Matrix& matrix) {
    for (int i = 0; i < matrix.n; i++) {
        delete[] matrix.data[i];
    }
    delete[] matrix.data;
}