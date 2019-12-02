#pragma once

#include "Matrix.h"

class Size {
public:
    Size();
    Size(const Size& src);
    Size(unsigned int x, unsigned int y);
    unsigned int x;
    unsigned int y;
    bool operator == (const Size second);
    bool operator != (const Size second);
    bool isZero();
};
