//
// Created by maciek on 15/01/2020.
//

#include <QPalette>
#include <QLabel>
#include <QPainter>
#include <QBrush>
#include <QWidget>

#include "playfield.h"

PlayField::PlayField(QWidget *parent) : QWidget(parent){
    grid = new Grid;
    pacMan = new Avatar;
    pixMap = new QPixmap("fieldMap.jpg");
    setPalette(QPalette(QColor(100, 100, 200)));
    setAutoFillBackground(true);
    newGame();
}


void PlayField::paintEvent(QPaintEvent * /* event */) {
    QPainter painter(this);
    painter.drawPixmap(0,0, this->width(), this->height(), *pixMap);
    paintPoints();
    paintPacMan();
    paintWalls();
}

void PlayField::newGame() {
    update();
    grid->newGame();
}

void PlayField::paintPoints() {
    QPainter painter(this);
    painter.setPen(Qt::yellow);
    painter.setBrush(Qt::yellow);
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    for (int i = 0; i < Y_GRID_SIZE; ++i) {
        for (int j = 0; j < X_GRID_SIZE; ++j) {
            if(grid->grid[i][j].smallPoint){
                QRect rect(0,0,xLength / 4 ,yLength / 4);
                rect.moveCenter(QPoint(j * xLength + xLength / 2, i * yLength + yLength / 2));
                painter.drawEllipse(rect);
            }
            if(grid->grid[i][j].bigPoint){
                QRect rect(0,0,xLength / 2, yLength / 2);
                rect.moveCenter(QPoint(j * xLength + xLength / 2, i * yLength + yLength / 2));
                painter.drawEllipse(rect);
            }
        }
    }

}

void PlayField::paintPacMan() {
    QPainter painter(this);
    painter.setPen(Qt::yellow);
    painter.setBrush(Qt::yellow);
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    QRect rect(0, 0, xLength * 3 / 4, yLength * 3 / 4);
    pacMan->getGridPos();
    rect.moveCenter(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2, pacMan->getGridPos().y() * yLength + yLength / 2));
    painter.drawEllipse(rect);
}

void PlayField::paintWalls() {
    QPainter painter(this);
    painter.setPen(Qt::darkBlue);
    painter.setBrush(Qt::darkBlue);
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    for (int i = 0; i < Y_GRID_SIZE; ++i) {
        for (int j = 0; j < X_GRID_SIZE; ++j) {
            if(grid->grid[i][j].wall){
                QRect rect(0,0,xLength * 3 / 4, yLength * 3 / 4);
                rect.moveCenter(QPoint(j * xLength + xLength / 2, i * yLength + yLength / 2));
                painter.drawRect(rect);
            }

        }
    }
}

void PlayField::movPacManUp() {
    pacMan->setGridPos(QPoint(pacMan->getGridPos().x(), pacMan->getGridPos().y() - 1));
    update();
}

void PlayField::movPacManDown() {
    pacMan->setGridPos(QPoint(pacMan->getGridPos().x(), pacMan->getGridPos().y() + 1));
    update();
}

void PlayField::movPacManRight() {
    pacMan->setGridPos(QPoint(pacMan->getGridPos().x() + 1, pacMan->getGridPos().y()));
    update();
}

void PlayField::movPacManLeft() {
    pacMan->setGridPos(QPoint(pacMan->getGridPos().x() - 1, pacMan->getGridPos().y()));
    update();
}
