#pragma once
#ifndef Matrix_h
#define Matrix_h
#include <iostream>
class Matrix {
    private:
        int x, y;
        int** elements;
        friend const Matrix operator+(const Matrix& m1, const Matrix& m2);
        friend const Matrix operator*(const Matrix& m1, const Matrix& m2);
        friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
    public:
        Matrix() = default;
        Matrix(const int& x, const int& y, const int** elements);
        Matrix(const int& x, const int& y);
        ~Matrix();
        Matrix(const Matrix& other);
        int getX() const;
        int getY() const;
        Matrix& operator=(const Matrix& other);
        Matrix& operator+=(const Matrix& other);
        Matrix& operator*=(const int& l);
        Matrix operator*(const int& l) const; // multiply by int
        int* operator[](int x);
        const int* operator[](int x) const;
        Matrix T() const; // Transposition
};

const Matrix operator+(const Matrix& m1, const Matrix& m2); // add two matrices
const Matrix operator*(const Matrix& m1, const Matrix& m2); // multiply two matrices
std::ostream& operator<<(std::ostream& out, const Matrix& m);
#endif
