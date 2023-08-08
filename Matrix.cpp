#include "Matrix.h"


Matrix::Matrix(const int& x, const int& y, const int** elements) : x(x),
y(y), 
elements(new int*[x]) 
{
    for (int i = 0; i < x; ++i) {
        this -> elements[i] = new int[y];
        for (int j = 0; j < y; ++j) {
            this->elements[i][j] = elements[i][j];
        }
    }
}
Matrix::Matrix(const int& x, const int& y): x(x), 
y(y), 
elements(new int* [x]) 
{
    for (int i = 0; i < x; ++i) {
        this->elements[i] = new int[y];
        for (int j = 0; j < y; ++j) {
            this->elements[i][j] = 0;
        }
    }
}
Matrix::~Matrix() 
{
    for (int i = 0; i < x; ++i) {
        delete[] this->elements[i];
    }
    delete[] this->elements;
}
Matrix::Matrix(const Matrix& other) : x(other.x), y(other.y), elements(new int* [other.x]) {
    for (int i = 0; i < x; ++i) {
        this->elements[i] = new int[other.y];
        for (int j = 0; j < y; ++j) {
            this->elements[i][j] = other.elements[i][j];
        }
    }
}
int Matrix::getX() const { return x; }
int Matrix::getY() const { return y; }
Matrix& Matrix::operator=(const Matrix& other){
    x = other.x;
    y = other.y;
    for (int i = 0; i < x; ++i) {
        delete[] this->elements[i];
    }
    delete[] this->elements;
    elements = new int* [x];
    for (int i = 0; i < x; ++i) {
        this->elements[i] = new int[y];
        for (int j = 0; j < y; ++j) {
            this->elements[i][j] = other.elements[x][y];
        }
    }
}
Matrix& Matrix::operator+=(const Matrix& other) {
    if (other.x != x || other.y != y) {
        return *this; // TODO: change later;
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            this->elements[i][j] += other.elements[i][j];
        }
    }
    return *this;
}
Matrix& Matrix::operator*=(const int& l) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            elements[i][j] *= l;
        }
    }
}
Matrix Matrix::operator*(const int& l) const{
    Matrix copy;
    copy = *this;
    copy *= l;
    return copy;
}
int* Matrix::operator[](int x){
    if (x > this->x) {
        return elements[x];// TODO : change later
    }
    return elements[x];
}
const int* Matrix::operator[](int x) const{
    if (x > this->x) {
        return elements[x];// TODO : change later
    }
    return elements[x];
}
Matrix Matrix::T() const{
    Matrix copy;
    copy.x = y;
    copy.y = x;
    copy.elements = new int* [y];
    for (int i = 0; i < y; i++)
    {
        copy.elements[i] = new int[x];
        for (int j = 0; j < x; j++)
        {
            copy.elements[i][j] = elements[j][i];
        }
    }
    return copy;
}
const Matrix operator+(const Matrix& m1, const Matrix& m2) {
        Matrix copy(m1.getX(), m1.getY());
        copy += m1;
        copy += m2;
        return copy;
}
const Matrix operator*(const Matrix& m1, const Matrix& m2) {
    if (m1.y != m2.x) {
        return m1;// TODO: change later
    }
    Matrix mult(m1.x, m2.y);
    for (int i = 0; i < mult.x; ++i) {
        for(int j = 0; j < mult.y; ++j){
            for (int k = 0; k < m1.y; ++k) {
                mult[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return mult;
}
std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    for (int i = 0; i < m.x; ++i) {
        for (int j = 0; j < m.y; ++j) {
            out << m.elements[i][j];
            if (j + 1 != m.y) {
                out << " ";
            }
        }
        if (i + 1 != m.x) {
            out << std::endl;
        }
        
    }
    return out;
}