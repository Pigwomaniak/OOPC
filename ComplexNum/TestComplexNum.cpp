#include <iostream>
#include "ComplexNum.h"

using namespace std;

int main() {
    ComplexNum a(1, 1);
    ComplexNum b(8, 4);
    ComplexNum c(2, 5);

    cout << a.re << "  " << a.im << endl;
    cout << b.re << "  " << b.im << endl;
    cout << c.re << "  " << c.im << endl;
    cout << b.phase() << endl;
    cout << c.amplitude() << endl;
    a = b + c;
    cout << a.re << "  " << a.im << endl;
    cout << a << endl;
    return 0;
}
