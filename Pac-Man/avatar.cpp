//
// Created by maciek on 15/01/2020.
//

#include "avatar.h"

Avatar::Avatar() {
    homePos = QPoint(13,23);
    gridPos =  QPoint(13,23);
    moveState = stay;
    color = Qt::yellow;
    //animationTime = 20;


}
/*
void Avatar::paintAvatar(QPainter* painter, int xLength, int yLength) {
    painter->setPen(color);
    painter->setBrush(color);
    QRect rect(0, 0, xLength * 3 / 4, yLength * 3 / 4);
    rect.moveCenter(getAvatarPixPos());
    painter->drawEllipse(rect);
}

*/