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

Matrix &Matrix::operator=(const Matrix &src) {
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


