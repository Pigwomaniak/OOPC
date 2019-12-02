#include <fstream>
#include "Matrix.h"
#include <sstream>


using namespace std;

Matrix::Matrix() {
    tab = nullptr;
    size.x = 0;
    size.y = 0;
}

Matrix::Matrix(const Matrix& src) {
    size = src.size;
    newTab();
    copyTab(*this, src);
}

Matrix::Matrix(unsigned int x, unsigned int y) {
    size.x = x;
    size.y = y;
    newTab();
    zeroTab();
}

Matrix::Matrix(double src) {
    size.y = 1;
    size.x = 1;
    newTab();
    tab[0][0] = src;
}

Matrix::~Matrix() {
    freeTab();
}

Matrix &Matrix::operator = (const Matrix &src) {
    if(size != src.size){
        freeTab();
        size = src.size;
        newTab();
    }
    for (unsigned int j = 0; j < size.y; ++j) {
        for (unsigned int k = 0; k < size.x; ++k) {
            tab[k][j] = src.tab[k][j];
        }
    }
    return *this;
}

Matrix operator+(const Matrix &prev, const Matrix &src) {
    if(!canAdd(prev.size, src.size)){
        //throw
    }
    if(prev.size.y == 1 && prev.size.x == 1){
        Matrix out(src);
        out.increaseTabBy(prev.tab[0][0]);
        return out;
    }
    if(src.size.y == 1 && src.size.x == 1){
        Matrix out(prev);
        out.increaseTabBy(src.tab[0][0]);
        return out;
    }
    Matrix out(prev);
    for (unsigned int i = 0; i < prev.size.y; ++i) {
        for (unsigned int j = 0; j < prev.size.x; ++j) {
            out.tab[j][i] += src.tab[j][i];
        }
    }
    return Matrix();
}

bool canAdd(Size first, Size second) {
    if(first == Size{1, 1} || second == Size{1, 1}) return true;
    if(first == second) return true;
    return false;
}

void Matrix::addElement(double element, unsigned int x, unsigned int y) {
    if(y >= size.y || x >= size.x) { //zmiana
        resizeTab(Size{max(x + 1, size.x), max(y + 1, size.y)});
    }
    tab[x][y] = element;
}

void Matrix::resizeTab(Size newSize) {
    Matrix temp (*this);
    freeTab();
    size = newSize;
    newTab();
    zeroTab();
    copyTab(*this, temp);
}


void Matrix::freeTab() {
    if(tab){
        for (unsigned int i = 0; i < size.x; ++i) {
            if(tab[i]){
                delete[] tab[i];
            }
        }
    }
    delete[] tab;
}

void Matrix::newTab() {
    tab = new double* [size.x];
    for (unsigned int i = 0; i < size.x; ++i) {
        tab[i] = new double[size.y];
    }
}

void Matrix::zeroTab() {
    for (unsigned int j = 0; j < size.y; ++j) {
        for (unsigned int k = 0; k < size.x; ++k) {
            tab[k][j] = 0;
        }
    }
}

void Matrix::increaseTabBy(double number) {
    for (unsigned int j = 0; j < size.y; ++j) {
        for (unsigned int k = 0; k < size.x; ++k) {
            tab[k][j] += number;
        }
    }
}

Matrix Matrix::readMatrixFromFile(const char* fileName) {
    Matrix out;
    ifstream file;
    file.open(fileName, ios::in);
    string readingLine;
    double temp = 0;
    unsigned int line = 0;
    unsigned int row = 0;
    while(getline(file, readingLine)){
        istringstream sReadingLine(readingLine);
        while (sReadingLine >> temp){
            out.addElement(temp,line, row++);
        }
        line++;
    }
    file.close();
    return out;
}

double& Matrix::operator()(unsigned int x, unsigned int y) {
    addElement(0, x, y);
    return (tab[x][y]);
}

void Matrix::copyTab(Matrix &dest, const Matrix &src) {
    for (unsigned int i = 0; i < src.size.y; ++i) {
        for (unsigned int j = 0; j < src.size.x; ++j) {
            dest.tab[j][i] = src.tab[j][i];
        }
    }
}

std::iostream& operator << (std::iostream& out, const Matrix& src){
	/*
	for (unsigned int i = 0; i < src.size.y; ++i){
		out << "| ";
		for (unsigned int j = 0; j < src.size.x; ++j){
			//out << (src.tab[j][i]) << " ";
		}
		out << "|" << std::endl;
	}
	*/
	return out;
}






