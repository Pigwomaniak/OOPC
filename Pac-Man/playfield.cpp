//
// Created by maciek on 15/01/2020.
//

#include <QPalette>
#include <QLabel>
#include <QPainter>
#include <QBrush>
#include <QWidget>
#include <QShortcut>
//#include <QTimer>

#include "playfield.h"

PlayField::PlayField(QWidget *parent) : QWidget(parent){
    grid = new Grid;
    pacMan = new Avatar;
    timerPacMan = new QTimer(this);
    connect(timerPacMan, SIGNAL(timeout()), this, SLOT(timeToMovPacMan()));

    ghostTimer = new QTimer(this);


    ghostSpeeder = new GhostSpeeder;
    timerGhostSpeeder = new QTimer(this);
    connect(timerGhostSpeeder, SIGNAL(timeout()), this, SLOT(timeToMovGhostSpider()));

    pixMap = new QPixmap("fieldMap.jpg");
    setPalette(QPalette(QColor(0, 0, 0)));
    setAutoFillBackground(true);
    newGame();
}


void PlayField::paintEvent(QPaintEvent * /* event */) {
    //QPainter painter(this);
    //painter.drawPixmap(0,0, this->width(), this->height(), *pixMap);
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;

    paintPoints();

    paintWalls();
    paintAvatar(pacMan);
    paintAvatar(ghostSpeeder);

}

void PlayField::newGame() {
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    grid->newGame();
    pacMan->goHome();

    pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                   pacMan->getGridPos().y() * yLength + yLength / 2));

    ghostSpeeder->goHome();
    ghostSpeeder->setAvatarPixPos(QPoint(ghostSpeeder->getGridPos().x() * xLength + xLength / 2,
                                         ghostSpeeder->getGridPos().y() * yLength + yLength / 2));
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

void PlayField::paintAvatar(Avatar* avatar) {
    QPainter painter(this);
    painter.setPen(avatar->getColor());
    painter.setBrush(avatar->getColor());
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    QRect rect(0, 0, xLength * 3 / 4, yLength * 3 / 4);
    //rect.moveCenter(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2, pacMan->getGridPos().y() * yLength + yLength / 2));
    rect.moveCenter(avatar->getAvatarPixPos());
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
        int xLength = width() / X_GRID_SIZE;
        int yLength = height() / Y_GRID_SIZE;

        pacMan->setState(Avatar::up);
        pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                       pacMan->getGridPos().y() * yLength + yLength / 2));
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = false;
        pacMan->setGridPos(requestPos);
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = true;
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
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = false;
        pacMan->setGridPos(requestPos);
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = true;
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
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = false;
        pacMan->setGridPos(requestPos);
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = true;
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
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = false;
        pacMan->setGridPos(requestPos);
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = true;
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


void PlayField::movAvatar(Avatar* avatar, QTimer* timer) {
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    int speedPacMan = 1;
    /*
    if(avatar == nullptr || timer == nullptr )
        return;
        */
    QPoint endPoint(avatar->getGridPos().x() * xLength + xLength / 2,
                    avatar->getGridPos().y() * yLength + yLength / 2);
    if(avatar->getState() == Avatar::stay){
        timer->stop();
        return;
    }
    if((avatar->getState() == Avatar::up) || (avatar->getState() == Avatar::down)){
        speedPacMan = yLength / 10;
        if(speedPacMan <= 0) speedPacMan = 1;
        if(avatar->getState() == Avatar::up) {
            speedPacMan *= -1;
            if (avatar->getAvatarPixPos().y() <= endPoint.y()) {
                avatar->setState(Avatar::stay);
                avatar->setAvatarPixPos(endPoint);
                timer->stop();
                update();
                return;
            }
        }
        if(avatar->getState() == Avatar::down) {
            if (avatar->getAvatarPixPos().y() >= endPoint.y()) {
                avatar->setState(Avatar::stay);
                avatar->setAvatarPixPos(endPoint);
                timer->stop();
                update();
                return;
            }
        }

        avatar->setAvatarPixPos(QPoint(avatar->getAvatarPixPos().x(), avatar->getAvatarPixPos().y() + speedPacMan));

    }
    if((avatar->getState() == Avatar::left) || (avatar->getState() == Avatar::right)){
        speedPacMan = xLength / 10;
        if(speedPacMan <= 0) speedPacMan = 1;
        if(avatar->getState() == Avatar::left) {
            speedPacMan *= -1;
            if (avatar->getAvatarPixPos().x() <= endPoint.x()) {
                avatar->setState(Avatar::stay);
                avatar->setAvatarPixPos(endPoint);
                timer->stop();
                update();
                return;
            }
        }
        if(pacMan->getState() == Avatar::right) {
            if (avatar->getAvatarPixPos().x() >= endPoint.x()) {
                avatar->setState(Avatar::stay);
                avatar->setAvatarPixPos(endPoint);
                timer->stop();
                update();
                return;
            }
        }
        avatar->setAvatarPixPos(QPoint(avatar->getAvatarPixPos().x() + speedPacMan, avatar->getAvatarPixPos().y()));
    }
    update();
}

void PlayField::timeToMoveGhosts() {

}



