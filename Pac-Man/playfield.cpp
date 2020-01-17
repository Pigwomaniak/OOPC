//
// Created by maciek on 15/01/2020.
//

#include <QPalette>
#include <QLabel>
#include <QPainter>
#include <QBrush>
#include <QWidget>
#include <QShortcut>
#include <QTimer>

#include "playfield.h"

PlayField::PlayField(QWidget *parent) : QWidget(parent){
    grid = new Grid;
    pacMan = new Avatar;
    timerPacMan = new QTimer(this);
    connect(timerPacMan, SIGNAL(timeout()), this, SLOT(movPacMan()));
    pixMap = new QPixmap("fieldMap.jpg");
    setPalette(QPalette(QColor(0, 0, 0)));
    setAutoFillBackground(true);
    newGame();
}


void PlayField::paintEvent(QPaintEvent * /* event */) {
    QPainter painter(this);
    //painter.drawPixmap(0,0, this->width(), this->height(), *pixMap);
    paintPoints();

    paintWalls();
    paintPacMan();
}

void PlayField::newGame() {
    grid->newGame();
    pacMan->goHome();
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                   pacMan->getGridPos().y() * yLength + yLength / 2));
    update();

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
    //rect.moveCenter(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2, pacMan->getGridPos().y() * yLength + yLength / 2));
    rect.moveCenter(pacMan->getAvatarPixPos());
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
    if(pacMan->getState() != Avatar::stay) return;

    QPoint requestPos(pacMan->getGridPos().x(), pacMan->getGridPos().y() - 1);
    if(grid->movCheck(requestPos)){
        pacMan->setState(Avatar::up);
        int xLength = width() / X_GRID_SIZE;
        int yLength = height() / Y_GRID_SIZE;
        pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                       pacMan->getGridPos().y() * yLength + yLength / 2));
        pacMan->setGridPos(requestPos);
        timerPacMan->start(ANIMATION_TIME_MS);
        update();
    }
    pointCheck(pacMan->getGridPos());
}

void PlayField::movPacManDown() {
    if(pacMan->getState() != Avatar::stay) return;
    QPoint requestPos(pacMan->getGridPos().x(), pacMan->getGridPos().y() + 1);
    if(grid->movCheck(requestPos)){
        pacMan->setState(Avatar::down);
        int xLength = width() / X_GRID_SIZE;
        int yLength = height() / Y_GRID_SIZE;
        pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                       pacMan->getGridPos().y() * yLength + yLength / 2));
        pacMan->setGridPos(requestPos);
        timerPacMan->start(ANIMATION_TIME_MS);
        update();
    }
    pointCheck(pacMan->getGridPos());
}

void PlayField::movPacManRight() {
    if(pacMan->getState() != Avatar::stay) return;
    QPoint requestPos(pacMan->getGridPos().x() + 1, pacMan->getGridPos().y());
    if(grid->movCheck(requestPos)){
        pacMan->setState(Avatar::right);
        int xLength = width() / X_GRID_SIZE;
        int yLength = height() / Y_GRID_SIZE;
        pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                       pacMan->getGridPos().y() * yLength + yLength / 2));
        pacMan->setGridPos(requestPos);
        timerPacMan->start(ANIMATION_TIME_MS);
        update();

    }
    pointCheck(pacMan->getGridPos());
}

void PlayField::movPacManLeft() {
    if(pacMan->getState() != Avatar::stay) return;
    QPoint requestPos(pacMan->getGridPos().x() - 1, pacMan->getGridPos().y());
    if(grid->movCheck(requestPos)){
        pacMan->setState(Avatar::left);
        int xLength = width() / X_GRID_SIZE;
        int yLength = height() / Y_GRID_SIZE;
        pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                       pacMan->getGridPos().y() * yLength + yLength / 2));
        pacMan->setGridPos(requestPos);
        timerPacMan->start(ANIMATION_TIME_MS);
        update();
    }
    pointCheck(pacMan->getGridPos());
}

void PlayField::pointCheck(QPoint toCheckPoint) {
    if(grid->checkSmallPoint(toCheckPoint)){
        emit getPoint();
    }
}


void PlayField::movPacMan() {
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    int speedPacMan = 1;
    QPoint endPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                    pacMan->getGridPos().y() * yLength + yLength / 2);
    if(pacMan->getState() == Avatar::stay){
        timerPacMan->stop();
        return;
    }
    if((pacMan->getState() == Avatar::up) || (pacMan->getState() == Avatar::down)){
        speedPacMan = yLength / 10;
        if(speedPacMan <= 0) speedPacMan = 1;
        if(pacMan->getState() == Avatar::up) {
            speedPacMan *= -1;
            if (pacMan->getAvatarPixPos().y() <= endPoint.y()) {
                pacMan->setState(Avatar::stay);
                pacMan->setAvatarPixPos(endPoint);
                timerPacMan->stop();
                update();
                return;
            }
        }
        if(pacMan->getState() == Avatar::down) {
            if (pacMan->getAvatarPixPos().y() >= endPoint.y()) {
                pacMan->setState(Avatar::stay);
                pacMan->setAvatarPixPos(endPoint);
                timerPacMan->stop();
                update();
                return;
            }
        }

        pacMan->setAvatarPixPos(QPoint(pacMan->getAvatarPixPos().x(), pacMan->getAvatarPixPos().y() + speedPacMan));

    }
    if((pacMan->getState() == Avatar::left) || (pacMan->getState() == Avatar::right)){
        speedPacMan = xLength / 10;
        if(speedPacMan <= 0) speedPacMan = 1;
        if(pacMan->getState() == Avatar::left) {
            speedPacMan *= -1;
            if (pacMan->getAvatarPixPos().x() <= endPoint.x()) {
                pacMan->setState(Avatar::stay);
                pacMan->setAvatarPixPos(endPoint);
                timerPacMan->stop();
                update();
                return;
            }
        }
        if(pacMan->getState() == Avatar::right) {
            if (pacMan->getAvatarPixPos().x() >= endPoint.x()) {
                pacMan->setState(Avatar::stay);
                pacMan->setAvatarPixPos(endPoint);
                timerPacMan->stop();
                update();
                return;
            }
        }
        pacMan->setAvatarPixPos(QPoint(pacMan->getAvatarPixPos().x() + speedPacMan, pacMan->getAvatarPixPos().y()));
    }
    update();
}


