#pragma once
#include <iostream>
//#include <Cref.h>


typedef struct Size{
    unsigned int x;
    unsigned int y;

    inline bool operator == ( const Size& src){
        return (x == src.x && y == src.y);
    };
    inline bool operator != (const Size& src){
        return (x != src.x || y != src.y);
    };
}Size;

class Matrix {

private:
    double** tab;
    Size size{};

    void addElement(double element, unsigned int x, unsigned int y);
    void resizeTab(Size newSize);
    void freeTab();
    void newTab();
    void zeroTab();
    void increaseTabBy(double number);
    void copyTab(Matrix& dest, const Matrix& src);
public:
    Matrix();
    Matrix(const Matrix& src);
    Matrix(unsigned int x, unsigned int y);
    Matrix(double src);
    ~Matrix();
    Matrix readMatrixFromFile(const char* fileName);
    double& operator ()(unsigned int x, unsigned int y);
    Matrix& operator = (const Matrix& src);
	friend std::iostream& operator << (std::iostream& out, const Matrix& src);
    friend Matrix operator + (const Matrix& prev, const Matrix& src);

};



bool canAdd(Size first, Size second);
