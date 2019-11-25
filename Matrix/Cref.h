#pragma once

#include "Matrix.h"

class Cref {
    friend class Matrix;
private:
    Matrix& mat;
public:
    Cref();
    ~Cref();
};
