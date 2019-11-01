#include "ComplexNum.h"
#include <cassert>

using namespace std;

int main() {
    ComplexNum a(1, 1);
    ComplexNum b(8, 8);
    ComplexNum c(3.5, 0);
    cout << a << "  " << b << " "<< c << endl;

    assert(c == 3.5);
    assert(3.5 == c);
    assert(a != c);
    assert(a == a);

    a += b += c;
    assert(a == ComplexNum(12.5, 9));
    assert(b == ComplexNum(11.5, 8));
    assert(c == ComplexNum(3.5));

    (a += b) += c;
    assert(a == ComplexNum(27.5, 17));
    assert(b == ComplexNum(11.5, 8));
    assert(c == ComplexNum(3.5));

    a *= b *= c;
    assert(a == ComplexNum(630.875, 1454.25));
    assert(b == ComplexNum(40.25, 28));
    assert(c == ComplexNum(3.5));

    (a *= b) *= c;
    assert(a == ComplexNum(-53641.984375, 266693.21875));
    assert(b == ComplexNum(40.25, 28));
    assert(c == ComplexNum(3.5));

    assert((c + 7) == ComplexNum(10.5));
    assert((7 + c) == ComplexNum(10.5));

    assert((b * 7) == ComplexNum(281.75, 196));
    assert((7 * b) == ComplexNum(281.75, 196));
    cout << a << "  " << b << " "<< c << endl;
    cout << "Test Complite" << endl;
    return 0;
}
