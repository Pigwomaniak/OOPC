#pragma once
#include <iostream>
#include "Cref.h"
#include "rcMatrix.h"



class Matrix {
    friend class rcMatrix;
private:
    rcMatrix* data;
public:
    Matrix(Matrix& src);
    Matrix& operator = (const Matrix& src);
    ~Matrix();
};
