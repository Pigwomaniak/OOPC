#include <Matrix.h>

using namespace std;

void test(const Matrix& m2x2, const Matrix& m2x3, const Matrix& m3x3);
void display(const Matrix& m1);

int main(){
    Matrix m2x2;
    m2x2(0, 0) = 1;
    m2x2(0, 1) = 2;
    m2x2(1, 0) = 3;
    m2x2(1, 0) = 4;

    Matrix m2x3;
    Matrix m3x3;
    test(m2x2, m2x3, m3x3);
}

void display(const Matrix m1){
    cout << "Matrix 2x2:" << endl << m1 << endl;
}