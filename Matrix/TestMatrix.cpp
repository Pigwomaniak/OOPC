#include <cassert>
#include "Matrix.h"

using namespace std;

void testRcMatrix();


void testReadFromFile(Matrix& m2x3, Matrix& m3x3);
void testFinal();
void display(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testComparison(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testAdd(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testSubstract(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testMultiply(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testAddEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testSubstractEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void testMultiplyEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);


int main(){
    testRcMatrix();

    testFinal();
    return 0;
}
void testRcMatrix(){
    rcMatrix newRc(Size(3, 3));
    //rcMatrix* new2RcPtr = newRc.detach();
    Matrix mat1(Size{4, 4});
    Matrix mat2(mat1);
    Matrix mat3(mat1);
}




void testFinal(){
    Matrix m2x2;
    Matrix m2x3;
    Matrix m3x3;

    m2x2(0, 0) = 1;
    m2x2(0, 1) = 2;
    m2x2(1, 0) = 3;
    m2x2(1, 1) = 4;
    try {
        testReadFromFile(m2x3, m3x3);
    }
    catch(File_read_fail& e) {
        cout << e.what() << endl;
    }
    display(m2x2, m2x3, m3x3);
    try {
        testComparison(m2x2, m2x3, m3x3);
    }
    catch(Wrong_size_of_matrix& e) {
        cout << e.what() << endl;
    }
    try {
        testAdd(m2x2, m2x3, m3x3);
        testAddEqual(m2x2, m2x3, m3x3);
    }
    catch(Wrong_size_of_matrix& e) {
        cout << e.what() << endl;
    }
    try {
        testSubstract(m2x2, m2x3, m3x3);
        testSubstractEqual(m2x2, m2x3, m3x3);
    }
    catch(Wrong_size_of_matrix& e) {
        cout << e.what() << endl;
    }
    try {
        testMultiply(m2x2, m2x3, m3x3);
        testMultiplyEqual(m2x2, m2x3, m3x3);
    }
    catch(Wrong_size_of_matrix& e) {
        cout << e.what() << endl;
    }
}





void display(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    cout << "Matrix 2x2:" << endl << m2x2 << endl;
    cout << "Matrix 2x3:" << endl << m2x3 << endl;
    cout << "Matrix 3x3:" << endl << m3x3 << endl;
    cout << "Matrix 2x2 (1, 1) = " << m2x2(1, 1) << endl;
}

void testReadFromFile(Matrix& m2x3, Matrix& m3x3){
    m2x3.readFromFile("matrix_2x3.txt");
    m3x3.readFromFile("matrix_3x3.txt");
    cout << "Read from file OK" << endl;
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
    assert(!(t2 != m3x3));
    t2(2, 2) = 50;
    assert(m3x3 != t2);

    Matrix t3 = 5;
    assert(t3 == 5);
    assert(5 == t3);
    assert(t3 != 6);
    assert(6 != t3);
    cout << "Comparison OK" << endl;
}

void testAdd(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    Matrix t1, t2(Size{2, 2}), t3;
    t1 = 1 + m2x2;
    t3 = m2x2 + 1;
    t2(0, 0) = 1;
    t2(0, 1) = 1;
    t2(1, 0) = 1;
    t2(1, 1) = 1;
    assert(t1 == (m2x2 + t2));
    assert(t3 == (m2x2 + t2));
    assert((m2x2 + t2)(1, 1) == 5);
    cout << "Add OK" << endl;
}


void testSubstract(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    Matrix t1(Size{1, 1}), t2(Size{2, 2}), t3;
    t1 = (1 - m2x2);
    t3 = m2x2 - 1;
    t2(0, 0) = 1;
    t2(0, 1) = 1;
    t2(1, 0) = 1;
    t2(1, 1) = 1;
    assert(t1 == (t2 - m2x2));
    assert(t3 == (m2x2 - t2));
    assert((m2x2 - t2)(1, 1) == 3);
    cout << "Substract OK" << endl;
}

void testMultiply(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    Matrix m1 = m2x3 * m3x3 * m3x3;
    assert(m1(1, 1) == 38);
    assert(m1(1, 0) == -38);
    assert(m1(0, 0) == -321);
    cout << "Multiply OK" << endl;
}

void testAddEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    Matrix t1 = m2x2;
    t1 += 1;
    Matrix t2 = t1 - 1;
    assert(m2x2 == t2);
    cout << "Add equal OK" << endl;
}
void testSubstractEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    Matrix t1 = m2x2;
    t1 -= 1;
    Matrix t2 = t1 + 1;
    assert(m2x2 == t2);
    cout << "Substract equal OK" << endl;
}
void testMultiplyEqual(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3){
    Matrix t1 = m2x2;
    t1 *= 1;
    assert(m2x2 == t1);
    Matrix t2 = m2x3;
    t2 *= m3x3;
    Matrix t3 = m2x3 * m3x3;
    assert(t2 == t3);
    cout << "Multiply equal OK" << endl;
}
