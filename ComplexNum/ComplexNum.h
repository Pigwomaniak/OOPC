#pragma once
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

    friend ComplexNum operator + (const ComplexNum& firstNum, const ComplexNum& secondNum);
	friend ComplexNum operator - (const ComplexNum& firstNum, const ComplexNum& secondNum);
	friend ComplexNum operator * (const ComplexNum& firstNum, const ComplexNum& secondNum);
	friend ComplexNum operator / (const ComplexNum& firstNum, const ComplexNum& secondNum);


    friend ostream &operator << (ostream &out, ComplexNum &c);
};


#endif //COMPLEXNUM_COMPLEXNUM_H
