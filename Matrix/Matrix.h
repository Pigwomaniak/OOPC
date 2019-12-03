#pragma once
#include <iostream>
#include "Cref.h"
#include "rcMatrix.h"


class Cref;
class Matrix {
    friend class rcMatrix;
private:
    rcMatrix* data;
public:
    Matrix();
    Matrix(const Matrix& src);
    Matrix(const Size& size);
    Matrix& operator = (const Matrix& src);
    ~Matrix();
    double operator()(unsigned int x, unsigned int y) const;
    Cref operator()(unsigned int x, unsigned int y);
    double read(unsigned int x, unsigned int y) const;
    void write(double element, unsigned int x, unsigned int y);
    void checkRange(unsigned int x, unsigned int y) const;

    friend  std::ostream& operator << (std::ostream& out, const Matrix& src);
    void readFromFile(const char* fileName);
};
