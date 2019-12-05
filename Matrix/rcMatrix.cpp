//
// Created by maciek on 02/12/2019.
//

#include "rcMatrix.h"
#include <algorithm>
#include <fstream>


rcMatrix::rcMatrix(const Size& size) {
    refCount = 1;
    this->size = size;
    if(this->size.isZero()){
        tab = nullptr;
        return ;
    }
    tab = new double* [size.x];
    for (unsigned int i = 0; i < size.x; ++i) {
        tab[i] = new double[size.y];
        for(unsigned int j = 0; j < size.y; ++j){
            tab[i][j] = 0;
        }
    }
}


rcMatrix::rcMatrix(const rcMatrix& src, const Size& newSize) {
    if(src.size.x < newSize.x || src.size.y < newSize.y){
        //throw
    }
    refCount = 1;
    this->size = newSize;
    tab = new double* [size.x];
    for (unsigned int i = 0; i < size.x; ++i) {
        tab[i] = new double[size.y];
        for(unsigned int j = 0; j < size.y; ++j){
            tab[i][j] = 0;
        }
    }
    for (unsigned int i = 0; i < src.size.x; ++i) {
        for(unsigned int j = 0; j < src.size.y; ++j){
            tab[i][j] = src.tab[i][j];
        }
    }
}

rcMatrix::rcMatrix(const double element) {
    size = Size{1, 1};
    tab = new double* [1];
    tab[0] = new double [1];
    tab[0][0] = element;
    refCount = 1;
}

rcMatrix::rcMatrix(const Size &size, const double element) {
    refCount = 1;
    this->size = size;
    tab = new double* [size.x];
    for (unsigned int i = 0; i < size.x; ++i) {
        tab[i] = new double[size.y];
        for(unsigned int j = 0; j < size.y; ++j){
            tab[i][j] = element;
        }
    }
}

rcMatrix *rcMatrix::detach() {
    if(refCount == 1){
        return this;
    }
    rcMatrix* out = new rcMatrix(*this, size);
    refCount--;
    return out;
}

rcMatrix::~rcMatrix() {
    for (unsigned int i = 0; i < size.x; ++i) {
        delete[] tab[i];
    }
    delete[] tab;
}

void rcMatrix::refCountIncrease() {
    refCount++;
}

Size rcMatrix::getSize() {
    return size;
}

unsigned int rcMatrix::getRefCount() {
    return refCount;
}

void rcMatrix::refCountDecrease() {
    refCount--;
}

double rcMatrix::readElement(unsigned int x, unsigned int y) {
    return tab[x][y];
}

void rcMatrix::writeElement(double element, unsigned int x, unsigned int y) {
    if(size.x <= x || size.y <= y){
        resize(Size{std::max(size.x, x + 1), std::max(size.y, y + 1)} );
    }
    tab[x][y] = element;
}

bool rcMatrix::inRange(unsigned int x, unsigned int y) {
    return (size.x > x && size.y > y);
}

void rcMatrix::resize(Size newSize) {
    rcMatrix temp(*this, newSize);
    freeTab();
    size = newSize;
    newTab();
    copyTab(temp);
}

void rcMatrix::freeTab() {
    if(tab){
        for (unsigned int i = 0; i < size.x; ++i) {
            delete[] tab[i];
        }
    }
    delete[] tab;

}

void rcMatrix::newTab() {
    tab = new double* [size.x];
    for (unsigned int i = 0; i < size.x; ++i) {
        tab[i] = new double[size.y];
        for(unsigned int j = 0; j < size.y; ++j){
            tab[i][j] = 0;
        }
    }
}

void rcMatrix::copyTab(const rcMatrix& src) {
    for (unsigned int i = 0; i < src.size.x; ++i) {
        for (unsigned int j = 0; j < src.size.y; ++j) {
            tab[i][j] = src.tab[i][j];
        }
    }
}

std::ostream &operator<<(std::ostream &out, const rcMatrix &src) {
    for (unsigned int i = 0; i < src.size.y; ++i) {
        out << "|\t";
        for (unsigned int j = 0; j < src.size.x; ++j) {
            out << src.tab[j][i] << "\t";
        }
        out << "|" << std::endl;
    }
    return out;
}

void rcMatrix::readFromFile(const char *fileName) {
    std::ifstream file;
    file.open(fileName, std::ifstream::in);
    if(!file.is_open() || !file.good()){
        //throw
    }
    file >> size.y;
    file >> size.x;
    freeTab();
    newTab();
    for (unsigned int i = 0; i < size.y; ++i) {
        for (unsigned int j = 0; j < size.x; ++j) {
            file >> tab[j][i];
        }
    }
    file.close();
}

bool rcMatrix::isSameMatrix(const rcMatrix &second) const {
    if(size != second.size){
        return false;
    }
    for (unsigned int i = 0; i < size.x; ++i) {
        for (unsigned int j = 0; j < size.y; ++j) {
            if(tab[i][j] != second.tab[i][j]){
                return false;
            }
        }
    }
    return true;
}

void rcMatrix::addToMatrix(double element) {
    for (unsigned int i = 0; i < size.x; ++i) {
        for (unsigned int j = 0; j < size.y; ++j) {
            tab[i][j] += element;
        }
    }
}

void rcMatrix::addToMatrix(const rcMatrix &matrix) {
    for (unsigned int i = 0; i < size.x; ++i) {
        for (unsigned int j = 0; j < size.y; ++j) {
            tab[i][j] += matrix.tab[i][j];
        }
    }
}

void rcMatrix::substractToMatrix(double element) {
    for (unsigned int i = 0; i < size.x; ++i) {
        for (unsigned int j = 0; j < size.y; ++j) {
            tab[i][j] -= element;
        }
    }
}

void rcMatrix::substractToMatrix(const rcMatrix &matrix) {
    for (unsigned int i = 0; i < size.x; ++i) {
        for (unsigned int j = 0; j < size.y; ++j) {
            tab[i][j] -= matrix.tab[i][j];
        }
    }
}

void rcMatrix::multiplyTabBy(double element) {
    for (unsigned int i = 0; i < size.x; ++i) {
        for (unsigned int j = 0; j < size.y; ++j) {
            tab[i][j] *= element;
        }
    }
}




