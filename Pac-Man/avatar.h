//
// Created by maciek on 15/01/2020.
//
#pragma once

#include <QPoint>

enum MoveState { stay = 0, right = 1, left = 2, up = 3, down = 4};

class Avatar {
public:
    Avatar();

    inline QPoint getGridPos() { return gridPos;};
    inline void setGridPos(QPoint newPos) { gridPos = newPos;};
    inline void goHome(){gridPos = homePos;};
    //inline QPoint getPixPos() { return pixPos;};

protected:
    QPoint homePos;
    QPoint gridPos;
    //QPoint pixPos;

};

