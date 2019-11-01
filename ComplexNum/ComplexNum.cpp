#include "ComplexNum.h"
#include <cmath>

ComplexNum::ComplexNum() {
    im = 0;
    re = 0;
}
ComplexNum::ComplexNum(double newRe) {
    im = 0;
    re = newRe;
}
ComplexNum::ComplexNum(double newRe, double newIm) {
    im = newIm;
    re = newRe;
}
ComplexNum::~ComplexNum() = default;
double ComplexNum::amplitude(){
    return sqrt(pow(re, 2) + pow(im, 2));
}
double ComplexNum::phase() {
    return atan2(im, re);
}
ComplexNum operator + (const ComplexNum& firstNum, const ComplexNum& secondNum) {
    ComplexNum out;
    out.im = firstNum.im + secondNum.im;
    out.re = firstNum.re + secondNum.re;
    return out;
}
ComplexNum operator - (const ComplexNum& firstNum, const ComplexNum& secondNum) {
    ComplexNum out;
    out.im = firstNum.im - secondNum.im;
    out.re = firstNum.re - secondNum.re;
    return out;
}
ComplexNum operator * (const ComplexNum& firstNum, const ComplexNum& secondNum) {
    ComplexNum out;
    out.re = ((firstNum.re*secondNum.re)-(firstNum.im * secondNum.im));
    out.im = ((firstNum.re * secondNum.im) + (firstNum.im * secondNum.re));
    return out;
}
ComplexNum operator / (const ComplexNum& firstNum, const ComplexNum& secondNum) {
    ComplexNum out;
    out.re = ((firstNum.re * secondNum.re) + (firstNum.im * secondNum.im))
            / (pow(secondNum.re, (double)2) + pow(secondNum.im, (double)2));
    out.im = ((firstNum.im * secondNum.re) - (firstNum.re * secondNum.im))
            / (pow(secondNum.re, (double)2) + pow(secondNum.im, (double)2));
    return out;
}
ostream &operator << (ostream &out, ComplexNum c){
    out << c.re << " +i" << c.im;
    return out;
}
bool operator == (const ComplexNum& firstNum, const ComplexNum& secondNum) {
    return ((firstNum.re == secondNum.re) && (secondNum.im == secondNum.im));
}
bool operator != (const ComplexNum& firstNum, const ComplexNum& secondNum) {
    return ((firstNum.re != secondNum.re) || (firstNum.im != secondNum.im));
}
ComplexNum& ComplexNum::operator += (const ComplexNum &secondNum) {
    return (*this = *this + secondNum);
}
ComplexNum& ComplexNum::operator -= (const ComplexNum &secondNum) {
    return (*this = *this - secondNum);
}
ComplexNum& ComplexNum::operator *= (const ComplexNum &secondNum) {
    return (*this = *this * secondNum);
}
ComplexNum& ComplexNum::operator /= (const ComplexNum &secondNum) {
    return (*this = *this / secondNum);
}