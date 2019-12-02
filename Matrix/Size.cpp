//
// Created by maciek on 02/12/2019.
//

#include "Size.h"

bool Size::operator==(const Size second) {
    return (x == second.x && y == second.y);
}

bool Size::operator!=(const Size second) {
    return (x != second.x || y != second.y);
}

Size::Size() {
    x = 0;
    y = 0;
}

Size::Size(const Size &src) {
    this->x = src.x;
    this->y = src.y;
}

Size::Size(unsigned int x, unsigned int y) {
    this->x = x;
    this->y = y;
}

bool Size::isZero() {
    return (x == 0 && y == 0);
}
