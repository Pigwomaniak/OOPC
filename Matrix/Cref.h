#pragma once

#include "Matrix.h"

class Cref {
    friend class Matrix;
private:
    //Matrix& mat;
    unsigned int x;
    unsigned int y;

public:
    Cref();
    ~Cref();

};
