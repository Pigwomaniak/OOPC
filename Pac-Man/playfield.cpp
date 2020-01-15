//
// Created by maciek on 15/01/2020.
//

#include <QPalette>
#include <QLabel>
#include <QPainter>

#include "playfield.h"

PlayField::PlayField(QWidget *parent) : QWidget(parent){
   pixMap = new QPixmap("fieldMap.JPG");
   setPalette(QPalette(QColor(100, 100, 200)));
   setAutoFillBackground(true);
   newGame();
}

void PlayField::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0,0, this->width(), this->height(), *pixMap);
}

void PlayField::newGame() {
    update();
}
