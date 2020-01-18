//
// Created by maciek on 17/01/2020.
//

#include "ghostSpeeder.h"

GhostSpeeder::GhostSpeeder() {
    homePos = QPoint(11,14);
    gridPos =  QPoint(11,14);
    moveState = stay;
    color = Qt::red;
}

QPoint GhostSpeeder::ghostDestPoint(Avatar* avatar, Grid* grid) {
    return avatar->getGridPos();
}
