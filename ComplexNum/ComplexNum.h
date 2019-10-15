//
// Created by maciek on 15/10/2019.
//

#ifndef COMPLEXNUM_COMPLEXNUM_H
#define COMPLEXNUM_COMPLEXNUM_H

#include <iostream>
using namespace std;

class ComplexNum {
public:
    ComplexNum();
    ComplexNum(double newRe, double newIm);
    ~ComplexNum();

    double re;
    double im;

    double amplitude();
    double phase();

    ComplexNum operator + (ComplexNum secondNum);
    ComplexNum operator - (ComplexNum secondNum);
    ComplexNum operator * (ComplexNum secondNum);
    ComplexNum operator / (ComplexNum secondNum);



    friend ostream &operator << (ostream &out, ComplexNum &c);
};


#endif //COMPLEXNUM_COMPLEXNUM_H
