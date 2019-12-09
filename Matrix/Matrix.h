#pragma once
#include <iostream>
#include "Cref.h"
#include "rcMatrix.h"

class rcMatrix;
class Cref;
class Wrong_size_of_matrix : public std::exception {
public:virtual const char* what () const throw () {
        return "Matrices have invalid dimensions for this operation.";
    }
};
class File_read_fail : public std::exception {
public:virtual const char* what () const throw () {
        return "File could not been read";
    }
};

class Matrix {
    friend class rcMatrix;
private:
    rcMatrix* data;
public:
    Matrix();
    Matrix(const Matrix& src);
    Matrix(const Size& size);
    Matrix(double element);
    Matrix& operator = (const Matrix& src);
    ~Matrix();
    double operator()(unsigned int x, unsigned int y) const;
    Cref operator()(unsigned int x, unsigned int y);
    double read(unsigned int x, unsigned int y) const;
    void write(double element, unsigned int x, unsigned int y);
    void checkRange(unsigned int x, unsigned int y) const;

    friend  std::ostream& operator << (std::ostream& out, const Matrix& src);
    void readFromFile(const char* fileName);
    bool isSameMatrix(const Matrix& second) const;
    bool canAdd(const Matrix& sec) const ;
    bool canMultiply(const Matrix& sec) const;

    friend Matrix operator + (const Matrix& prev, const Matrix& sec);
    friend Matrix operator - (const Matrix& prev, const Matrix& sec);
    friend Matrix operator * (const Matrix& prev, const Matrix& sec);

    Matrix&operator += (const Matrix& src);
    Matrix&operator -= (const Matrix& src);
    Matrix&operator *= (const Matrix& src);

};

bool operator == (const Matrix& first, const Matrix& second);
bool operator != (const Matrix& first, const Matrix& second);

