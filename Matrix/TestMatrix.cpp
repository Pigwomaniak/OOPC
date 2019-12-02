#include <cassert>
#include "Matrix.h"

using namespace std;

void testReadFromFile(Matrix& m2x3, Matrix& m3x3);
void test(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void display(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testComparison(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testAdd(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testSubstract(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testMultiply(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testAddEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testSubstractEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testMultiplyEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);


int main(){
    Matrix m2x2;

    m2x2(0, 0) = 1;
    m2x2(0, 1) = 2;
    m2x2(1, 0) = 3;
    m2x2(1, 1) = 4;

    Matrix m2x3;
    Matrix m3x3;
    //testReadFromFile(m2x3, m3x3);
    //test(m2x2, m2x3, m3x3);
}

void testReadFromFile(Matrix& m2x3, Matrix& m3x3){
    m2x3.readMatrixFromFile("matrix_2x3");
    m3x3.readMatrixFromFile("matrix_3x3");
}
/*
void test(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    display(m2x2, m2x3, m3x3);
    testComparison(m2x2, m2x3, m3x3);
    testAdd(m2x2, m2x3, m3x3);
    testSubstract(m2x2, m2x3, m3x3);
    testAddEqual(m2x2, m2x3, m3x3);
    testSubstractEqual(m2x2, m2x3, m3x3);
    testMultiply(m2x2, m2x3, m3x3);
    testMultiplyEqual(m2x2, m2x3, m3x3);
}

void display(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    cout << "Matrix 2x2:" << endl << m2x2 << endl;
    cout << "Matrix 2x3:" << endl << m2x3 << endl;
    cout << "Matrix 3x3:" << endl << m3x3 << endl;
}

void testComparison(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    Matrix t1 = m2x2;
    assert(t1 == t1);
    assert(t1 == m2x2);
    assert(!(t1 == m3x3));
    t1(1, 1) = 50;
    assert(!(t1 == m2x2));

    Matrix t2 = m3x3;
    assert(!(m3x3 != m3x3));
    assert(m2x2 != m2x3);
    assert(!(t2 == m3x3));
    t2(2, 2) = 50;
    assert(m3x3 != t2);

    Matrix t3 = 5;
    assert(t3 == 5);
    assert(5 == t3);
    assert(t3 != 6);
    assert(6 != t3);
}

void testAdd(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    Matrix t1, t2;
    t1 = 1 + m2x2;
    t2(0, 0) = 1;
    t2(0, 1) = 1;
    t2(1, 0) = 1;
    t2(1, 1) = 1;
    assert(t1 = m2x2 + t2);
}

void testSubstract(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){

}

void testMultiply(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){

}

void testAddEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){

}

void testSubstractEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){

}
void testMultiplyEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){

}
 */