#include "Header.h"
#include <iostream>

int main() {
    int n;

    do {
        std::cout << "Enter the size of the matrix (n): ";
        std::cin >> n;
    } while (n <= 0);

    try {
        Matrix matrix(n);

        matrix.inputSymmetricMatrix();

        std::cout << "Original matrix:\n";
        matrix.printMatrix();

        Matrix newMatrix = matrix.generateNewMatrix();
        std::cout << "\nNew matrix:\n";
        newMatrix.printMatrix();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
