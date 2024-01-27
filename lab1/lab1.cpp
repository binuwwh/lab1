#include "matrix.h"
#include <iostream>

int main() {
    try {
        int n;

        do {
            std::cout << "Enter the size of the matrix (n): ";
            std::cin >> n;

            if (std::cin.fail() || n <= 0) {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid input. Please try again.\n";
            }

        } while (std::cin.fail() || n <= 0);

        Matrix matrix = createMatrix(n);

        inputSymmetricMatrix(matrix);

        std::cout << "Original matrix:\n";
        printMatrix(matrix);

        Matrix newMatrix = generateNewMatrix(matrix);
        std::cout << "\nNew matrix:\n";
        printMatrix(newMatrix);

        destroyMatrix(matrix);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


//даст ошибку 1
// очищает буффер ввода
//Сброс флагов ошибки ввода.
//это объявление переменной e, которая будет использоваться для хранения информации об исключении.