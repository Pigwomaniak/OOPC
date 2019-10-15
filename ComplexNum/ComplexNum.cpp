//
// Created by maciek on 15/10/2019.
//

#include "ComplexNum.h"
#include <cmath>

ComplexNum::ComplexNum() {
    im = 0;
    re = 0;
}
ComplexNum::ComplexNum(double newre, double newim) {
    im = newim;
    re = newre;
}
ComplexNum::~ComplexNum() {

}
double ComplexNum::amplitude(){
    return sqrt(pow(re, 2) + pow(im, 2));
}
double ComplexNum::phase() {
    return atan2(im, re);
}
ComplexNum ComplexNum::operator + (ComplexNum secondNum) {
    ComplexNum out;
    out.im = this->im + secondNum.im;
    out.re = this->re + secondNum.re;
    return out;
}
ComplexNum ComplexNum::operator - (ComplexNum secondNum) {
    ComplexNum out;
    out.im = this->im - secondNum.im;
    out.re = this->re - secondNum.re;
    return out;
}
ComplexNum ComplexNum::operator*(ComplexNum secondNum) {
    ComplexNum out;
    out.re = ((this->re*secondNum.re)-(this->im * secondNum.im));
    out.im = ((this->re * secondNum.im) + (this->im * secondNum.re));
    return out;
}
ComplexNum ComplexNum::operator/(ComplexNum secondNum) {
    ComplexNum out;
    out.re = ((this->re * secondNum.re) + (this->im * secondNum.im)) / (pow(secondNum.re, (double)2) + pow(secondNum.im, (double)2));
    out.im = ((this->im * secondNum.re) - (this->re * secondNum.im)) / (pow(secondNum.re, (double)2) + pow(secondNum.im, (double)2));
    return out;
}


ostream &operator<< (ostream &out, ComplexNum &c){
    out << c.re << " +i" << c.im;
    return out;
}
