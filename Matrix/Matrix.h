#pragma once
#include <iostream>
#include <Cref.h>

typedef struct{
    unsigned int x;
    unsigned int y;
}Size;

class Matrix {

private:
    double** tab;
    Size size;
public:
    Matrix();
    Matrix(Matrix src);
    ~Matrix();


};