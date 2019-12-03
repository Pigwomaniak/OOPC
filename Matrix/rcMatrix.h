#pragma once

#include <iosfwd>
#include "Size.h"
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
    rcMatrix* detach();
    ~rcMatrix();
    void refCountIncrease();
    Size getSize();
    unsigned int getRefCount();
    void  refCountDecrease();
    double readElement(unsigned int x, unsigned int y);
    void writeElement(double element, unsigned int x, unsigned int y);
    bool inRange(unsigned int x, unsigned int y);
    friend std::ostream& operator << (std::ostream& out, const rcMatrix& src);
    void readFromFile(const char* fileName);

};





