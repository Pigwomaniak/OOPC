
#include "Cref.h"

Cref &Cref::operator=(double element) {
    this->matrix.write(element, x, y);
    return *this;
}

Cref::operator double() const {
    return matrix.read(x, y);
}
