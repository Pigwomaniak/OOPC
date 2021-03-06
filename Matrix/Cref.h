#pragma once

#include "Matrix.h"
class Matrix;
class Cref {
    
private:
	friend class Matrix;
    Matrix& matrix;
    unsigned int x;
    unsigned int y;
public:
    Cref(Matrix &matrix, unsigned int newX, unsigned int newY): matrix(matrix), x(newX), y(newY){};
    Cref&operator = (double element);
    operator double () const;


};
