#ifndef HEADER_H
#define HEADER_H

class Matrix {
private:
    int** data;
    int n; // ���������� size_t ��� ������� �������
    int sumOfDigits(int num);

public:
    explicit Matrix(int size); // ���������� ����� �������� ����� explicit
    ~Matrix();
    void inputSymmetricMatrix();
    Matrix generateNewMatrix();
    void printMatrix() const;
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

private:
    static void handleBadInput(); // ������� ����������� ������� ��� ��������� ������������� �����
};

#endif
