//
// Created by maciek on 02/12/2019.
//

#include "rcMatrix.h"
#include <algorithm>

rcMatrix::rcMatrix(const Size& size) {
    refCount = 1;
    this->size = size;
    tab = new double* [size.x];
    for (unsigned int i = 0; i < size.x; ++i) {
        tab[i] = new double[size.y];
        for(unsigned int j = 0; j < size.y; ++j){
            tab[i][j] = 0;
        }
    }
}


rcMatrix::rcMatrix(double ** src, const Size& size) {
    refCount = 1;
    this->size = size;
    tab = new double* [size.x];
    for (unsigned int i = 0; i < size.x; ++i) {
        tab[i] = new double[size.y];
        for(unsigned int j = 0; j < size.y; ++j){
            tab[i][j] = src[i][j];
        }
    }
}

rcMatrix *rcMatrix::detach() {
    if(refCount == 1){
        return this;
    }
    rcMatrix* out = new rcMatrix(tab, size);
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
    rcMatrix temp(tab, newSize);
    freeTab();
    size = newSize;
    newTab();
    copyTab(temp);
}

void rcMatrix::freeTab() {
    for (unsigned int i = 0; i < size.x; ++i) {
        delete[] tab[i];
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

