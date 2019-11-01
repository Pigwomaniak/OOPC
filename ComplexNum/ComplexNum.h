#pragma once
#include <iostream>
using namespace std;

class ComplexNum {
public:
    ComplexNum();
    ComplexNum(double newRe);
    ComplexNum(double newRe, double newIm);
    ~ComplexNum();

    double re;
    double im;

    double amplitude();
    double phase();

    friend ComplexNum operator + (const ComplexNum& firstNum, const ComplexNum& secondNum);
	friend ComplexNum operator - (const ComplexNum& firstNum, const ComplexNum& secondNum);
	friend ComplexNum operator * (const ComplexNum& firstNum, const ComplexNum& secondNum);
	friend ComplexNum operator / (const ComplexNum& firstNum, const ComplexNum& secondNum);
    friend ostream &operator << (ostream &out, ComplexNum c);

    friend bool operator == (const ComplexNum& firstNum, const ComplexNum& secondNum);
    friend bool operator != (const ComplexNum& firstNum, const ComplexNum& secondNum);

    ComplexNum& operator += (const ComplexNum& secondNum);
    ComplexNum& operator -= (const ComplexNum& secondNum);
    ComplexNum& operator *= (const ComplexNum& secondNum);
    ComplexNum& operator /= (const ComplexNum& secondNum);
};
