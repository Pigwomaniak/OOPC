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

Matrix operator+(const Matrix &prev, const Matrix &sec) {
    if(prev.data->getSize().isOne()){

    }
    if(sec.data->getSize().isOne()){

    }
    return Matrix();
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