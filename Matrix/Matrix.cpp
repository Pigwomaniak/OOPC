#include <fstream>
#include <sstream>
#include "Matrix.h"


using namespace std;

Matrix::Matrix() {
    data = new rcMatrix(Size{0, 0});
}

Matrix::Matrix(const Matrix &src) {
    src.data->refCountIncrease();
    data = src.data;
}

Matrix::Matrix(const double element) {
    data = new rcMatrix(element);
}

Matrix &Matrix::operator=(const Matrix &src) {
    data->refCountDecrease();
    if(data->getRefCount() == 0){
        delete data;
    }
    src.data->refCountIncrease();
    data = src.data;
    return *this;
}

Matrix::~Matrix() {
    data->refCountDecrease();
    if(data->getRefCount() == 0){
        delete data;
    }
}

Matrix::Matrix(const Size &size) {
    data = new rcMatrix(size);
}

double Matrix::read(unsigned int x, unsigned int y) const {
    return data->readElement(x, y);
}

void Matrix::write(double element, unsigned int x, unsigned int y) {
    data = data->detach();
    data->writeElement(element, x, y);
}

double Matrix::operator()(unsigned int x, unsigned int y) const {
    checkRange(x, y);
    return data->readElement(x, y);
}

void Matrix::checkRange(unsigned int x, unsigned int y) const {
    if(data->inRange(x, y)){
        //throw
    }
}

Cref Matrix::operator()(unsigned int x, unsigned int y) {
    return Cref(*this, x, y);
}

std::ostream& operator << (std::ostream &out, const Matrix &src) {
    out << *(src.data);
    return out;
}

void Matrix::readFromFile(const char *fileName) {
    data->readFromFile(fileName);
}

Matrix operator + (const Matrix &prev, const Matrix &sec) {
    if (prev.canAdd(sec)){
        //throw cant add;
    }
    if(prev.data->getSize().isOne() && !sec.data->getSize().isOne()){
        Matrix out(sec);
        out.data = out.data->detach();
        out.data->addToMatrix(prev(0, 0));
        return out;
    }
    if(sec.data->getSize().isOne() && !prev.data->getSize().isOne()){
        Matrix out(prev);
        out.data = out.data->detach();
        out.data->addToMatrix(sec(0, 0));
        return out;
    }
    Matrix out(prev);
    out.data = out.data->detach();
    out.data->addToMatrix(*sec.data);
    return out;
}

bool Matrix::isSameMatrix(const Matrix &second) const {
    if(data == second.data){
        return true;
    }
    return data->isSameMatrix(*second.data);
}

bool operator==(const Matrix &first, const Matrix &second) {
    return first.isSameMatrix(second);
}
bool operator!=(const Matrix &first, const Matrix &second) {
    return !first.isSameMatrix(second);
}
bool Matrix::canAdd(const Matrix &sec) const {
    if(data->getSize().isZero() || sec.data->getSize().isZero()){
        return false;
    }
    if(data->getSize().isOne() || sec.data->getSize().isOne())
        return true;
    if (data->getSize() == sec.data->getSize())
        return true;
    return false;
}
Matrix operator-(const Matrix &prev, const Matrix &sec) {
    if (prev.canAdd(sec)){
        //throw cant add;
    }
    if(prev.data->getSize().isOne() && !sec.data->getSize().isOne()){ // dodć zmianę znaku np przez mnożenie
        Matrix out(sec);
        out.data = out.data->detach();
        out.data->multiplyTabBy(-1);
        out.data->addToMatrix(prev(0, 0));
        return out;
    }
    if(sec.data->getSize().isOne() && !prev.data->getSize().isOne()){
        Matrix out(prev);
        out.data = out.data->detach();
        out.data->substractToMatrix(sec(0, 0));
        return out;
    }
    Matrix out(prev);
    out.data = out.data->detach();
    out.data->substractToMatrix(*sec.data);
    return out;
}

bool Matrix::canMultiply(const Matrix &sec) const {
    if(data->getSize().x == sec.data->getSize().y){
        return true;
    }
    if(data->getSize().isOne() || sec.data->getSize().isOne()){
        return true;
    }
    return false;
}


Matrix operator*(const Matrix &prev, const Matrix &sec) {
    if(prev.canMultiply(sec)){
        // throw
    }
    if(prev.data->getSize().isOne() && !sec.data->getSize().isOne()){
        Matrix out(sec);
        out.data = out.data->detach();
        out.data->multiplyTabBy(prev(0, 0));
        return out;
    }
    if(!prev.data->getSize().isOne() && sec.data->getSize().isOne()){
        Matrix out(prev);
        out.data = out.data->detach();
        out.data->multiplyTabBy(sec(0, 0));
        return out;
    }
    Matrix out (Size{sec.data->getSize().x, prev.data->getSize().y});
    out.data->multiplyTabByTab(*prev.data, *sec.data);

    return out;
}

Matrix &Matrix::operator+=(const Matrix &src) {
    *this = *this + src;
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &src) {
    *this = *this - src;
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &src) {
    *this = *this * src;
    return *this;
}
