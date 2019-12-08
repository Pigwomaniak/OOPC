#pragma once

#include <iosfwd>
#include "Size.h"
#include "Matrix.h"

#include <iostream>

class rcMatrix {
private:
    double** tab;
    Size size;
    unsigned int refCount;
    void resize(Size newSize);
    void freeTab();
    void newTab();
    void copyTab(const rcMatrix& src);

public:
    rcMatrix(const Size& size);
    rcMatrix(const rcMatrix& src, const Size& NewSize);
    rcMatrix(double element);
    rcMatrix(const Size& size, double element);
    rcMatrix* detach();
    ~rcMatrix();
    void refCountIncrease();
    void refCountDecrease();
    Size getSize() const ;
    unsigned int getRefCount() const;
    double readElement(unsigned int x, unsigned int y) const;
    void writeElement(double element, unsigned int x, unsigned int y);
    bool inRange(unsigned int x, unsigned int y) const;
    friend std::ostream& operator << (std::ostream& out, const rcMatrix& src);
    void readFromFile(const char* fileName);
    bool isSameMatrix(const rcMatrix& second) const ;
    void addToMatrix(double element);
    void addToMatrix(const rcMatrix& matrix);
    void substractToMatrix(double element);
    void substractToMatrix(const rcMatrix& matrix);
    void multiplyTabBy(double element);
    void multiplyTabByTab(const rcMatrix& prev, const rcMatrix& sec);

};


