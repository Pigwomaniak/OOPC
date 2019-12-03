
#include "Cref.h"

Cref &Cref::operator=(double element) {
    this->matrix.write(element, x, y);
    return *this;
}
