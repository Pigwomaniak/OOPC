#pragma once
#include "Size.h"

class rcMatrix {
    //class Size;
private:
    double** tab;
    Size size;
    unsigned int refCount;
public:
    rcMatrix();
    rcMatrix* detach();
    ~rcMatrix();

};


