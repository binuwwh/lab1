#include "Header.h"
#include <iostream>
#include <stdexcept>
#include <climits>

int Matrix::sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

Matrix::Matrix(int size) {
    if (size == 0) {
        throw std::invalid_argument("The size of the matrix must be a positive number.");
    }
    n = size;
    data = new int* [n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[n];
    }
}

void Matrix::handleBadInput() {
    std::cin.clear(); // Очищаем флаг ошибки
    std::cin.ignore(INT_MAX, '\n');
    if (std::cin.eof()) {
        throw std::runtime_error("End of file reached. Program terminated.");
    }
    throw std::runtime_error("Invalid input. Please try again.");
}


void Matrix::inputSymmetricMatrix() {
    std::cout << "Enter elements for the symmetric matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int value;
            do {
                std::cout << "[" << i << "][" << j << "]: ";
                std::cin >> value;
                if (std::cin.fail()) {
                    handleBadInput();
                }
                else {
                    data[i][j] = value;
                    data[j][i] = value;
                }
            } while (std::cin.fail());
        }
    }
}


Matrix Matrix::generateNewMatrix() {
    int** newData = new int* [n];
    for (int i = 0; i < n; i++) {
        newData[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        int sum = sumOfDigits(data[i][n - 1]);

        for (int j = 0; j < n; j++) {
            if (sumOfDigits(data[i][j]) == sum) {
                newData[i][j] = data[i][j];
            }
            else {
                newData[i][j] = 0;
            }
        }
    }
    Matrix newMatrix(n);
    newMatrix.data = newData;
    return newMatrix;
}

void Matrix::printMatrix() const {
    std::cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << '\n';
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;
}

Matrix::Matrix(const Matrix& other) {
    n = other.n;
    data = new int* [n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[n];
        for (int j = 0; j < n; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;

    n = other.n;
    data = new int* [n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[n];
        for (int j = 0; j < n; j++) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}


