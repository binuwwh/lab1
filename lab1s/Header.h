#ifndef HEADER_H
#define HEADER_H

class Matrix {
private:
    int** data;
    int n; // Используем size_t для размера матрицы
    int sumOfDigits(int num);

public:
    explicit Matrix(int size); // Используем явное ключевое слово explicit
    ~Matrix();
    void inputSymmetricMatrix();
    Matrix generateNewMatrix();
    void printMatrix() const;
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

private:
    static void handleBadInput(); // Добавим статическую функцию для обработки некорректного ввода
};

#endif
