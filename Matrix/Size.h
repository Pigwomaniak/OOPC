#pragma once

class Size {
public:
    Size();
    Size(const Size& src);
    Size(unsigned int x, unsigned int y);
    unsigned int x;
    unsigned int y;
    bool operator == (const Size second) const ;
    bool operator != (const Size second) const ;
    bool isOne();
    bool isZero();

};
