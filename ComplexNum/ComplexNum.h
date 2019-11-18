#pragma once
#include <iostream>
using namespace std;

class ComplexNum {
public:
    ComplexNum();
    ComplexNum(double newRe);
    ComplexNum(double newRe, double newIm);

    double re;
    double im;

    double amplitude();
    double phase();


    ComplexNum& operator += (const ComplexNum& secondNum);
    ComplexNum& operator -= (const ComplexNum& secondNum);
    ComplexNum& operator *= (const ComplexNum& secondNum);
    ComplexNum& operator /= (const ComplexNum& secondNum);
};

ComplexNum operator + (const ComplexNum& firstNum, const ComplexNum& secondNum);
ComplexNum operator - (const ComplexNum& firstNum, const ComplexNum& secondNum);
ComplexNum operator * (const ComplexNum& firstNum, const ComplexNum& secondNum);
ComplexNum operator / (const ComplexNum& firstNum, const ComplexNum& secondNum);
ostream &operator << (ostream &out, const ComplexNum &c);

bool operator == (const ComplexNum& firstNum, const ComplexNum& secondNum);
bool operator != (const ComplexNum& firstNum, const ComplexNum& secondNum);
