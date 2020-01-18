//
// Created by maciek on 15/01/2020.
//

#include <QPalette>
//#include <QLabel>
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

    timerBoost = new QTimer(this);
    connect(timerBoost, SIGNAL(timeout()), this, SLOT(boostEnd()));

    ghostTimer = new QTimer(this);
    connect(ghostTimer, SIGNAL(timeout()), this, SLOT(timeToMoveGhosts()));
    ghostTimer->start(GHOST_SPEED);


    ghostSpeeder = new GhostSpeeder;
    timerGhostSpeeder = new QTimer(this);
    connect(timerGhostSpeeder, SIGNAL(timeout()), this, SLOT(timeToMoveGhostSpeeder()));

    ghostAmbush = new GhostAmbush;
    timerGhostAmbush = new QTimer(this);
    connect(timerGhostAmbush, SIGNAL(timeout()), this, SLOT(timeToMoveGhostAmbush()));

    ghostAmbush2 = new GhostAmbush;
    ghostAmbush2->setColor(Qt::green);
    ghostAmbush2->setHomePoint(QPoint(15,14));
    timerGhostAmbush2 = new QTimer(this);
    connect(timerGhostAmbush2, SIGNAL(timeout()), this, SLOT(timeToMoveGhostAmbush2()));

    //pixMap = new QPixmap("fieldMap.jpg");
    setPalette(QPalette(QColor(0, 0, 0)));
    setAutoFillBackground(true);

    strategy = WayFinder::seek;
    newGame();
}

void PlayField::boostEnd() {
    strategy = WayFinder::seek;
    timerBoost->stop();
}


void PlayField::paintEvent(QPaintEvent * /* event */) {
    //QPainter painter(this);
    //painter.drawPixMap(0,0, this->width(), this->height(), *pixMap);
    //int xLength = width() / X_GRID_SIZE;
    //int yLength = height() / Y_GRID_SIZE;

    paintPoints();

    paintWalls();
    paintAvatar(pacMan);
    paintAvatar(ghostSpeeder);
    paintAvatar(ghostAmbush);
    paintAvatar(ghostAmbush2);

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
    ghostAmbush->goHome();
    ghostAmbush->setAvatarPixPos(QPoint(ghostAmbush->getGridPos().x() * xLength + xLength / 2,
                                        ghostAmbush->getGridPos().y() * yLength + yLength / 2));
    ghostAmbush2->goHome();
    ghostAmbush2->setAvatarPixPos(QPoint(ghostAmbush2->getGridPos().x() * xLength + xLength / 2,
                                        ghostAmbush2->getGridPos().y() * yLength + yLength / 2));
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
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    if(grid->movCheck(requestPos) == Grid::normal){
        pacMan->setState(Avatar::right);
        pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                       pacMan->getGridPos().y() * yLength + yLength / 2));
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = false;
        pacMan->setGridPos(requestPos);
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = true;
        timerPacMan->start(ANIMATION_TIME_MS);
        update();

    }
    if(grid->movCheck(requestPos) == Grid::teleport){
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = false;
        requestPos = QPoint(pacMan->getGridPos().x() - X_GRID_SIZE, pacMan->getGridPos().y());
        pacMan->setGridPos(requestPos);
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = true;
        pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                       pacMan->getGridPos().y() * yLength + yLength / 2));
        update();
    }
    pointCheck(pacMan->getGridPos());
}

void PlayField::movPacManLeft() {
    if(pacMan->getState() != Avatar::stay) return;
    QPoint requestPos(pacMan->getGridPos().x() - 1, pacMan->getGridPos().y());
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    if(grid->movCheck(requestPos) == Grid::normal){
        pacMan->setState(Avatar::left);
        pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                       pacMan->getGridPos().y() * yLength + yLength / 2));
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = false;
        pacMan->setGridPos(requestPos);
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = true;
        timerPacMan->start(ANIMATION_TIME_MS);
        update();
    }
    if(grid->movCheck(requestPos) == Grid::teleport){
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = false;
        requestPos = QPoint(pacMan->getGridPos().x() + X_GRID_SIZE, pacMan->getGridPos().y());
        pacMan->setGridPos(requestPos);
        grid->grid[pacMan->getGridPos().y()][pacMan->getGridPos().x()].pacMan = true;
        pacMan->setAvatarPixPos(QPoint(pacMan->getGridPos().x() * xLength + xLength / 2,
                                       pacMan->getGridPos().y() * yLength + yLength / 2));
        update();
    }
    pointCheck(pacMan->getGridPos());
}

void PlayField::pointCheck(QPoint toCheckPoint) {
    if(grid->checkSmallPoint(toCheckPoint)){
        emit getPoint();
    }
    if(grid->checkBigPoint(toCheckPoint) && strategy == WayFinder::seek){
        strategy = WayFinder::runAway;
        timerBoost->start(BOOST_TIME);
    }
}


void PlayField::movAvatar(Avatar* avatar, QTimer* timer) {
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    int speedPacMan;
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
        if(avatar->getState() == Avatar::right) {
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
    movGhost(ghostSpeeder, timerGhostSpeeder, pacMan);
    movGhost(ghostAmbush, timerGhostAmbush, pacMan);
    movGhost(ghostAmbush2, timerGhostAmbush2, ghostSpeeder);

    update();
}

void PlayField::movGhost(GhostSpeeder *ghost, QTimer* timerGhost, Avatar* reference) {
    if(ghost->getState() != Avatar::stay) return;
    WayFinder waySpeeder(grid->getGridPtr(), ghost->getGridPos(),
                         ghost->ghostDestPoint(reference, grid));
    Avatar::MoveState newState = waySpeeder.findMovDirection2(strategy);
    if(newState == Avatar::stay){
        //ghostGetPacMan();
        return;
    }
    ghost->setState(newState);
    int xLength = width() / X_GRID_SIZE;
    int yLength = height() / Y_GRID_SIZE;
    ghost->setAvatarPixPos(QPoint(ghost->getGridPos().x() * xLength + xLength / 2,
                                  ghost->getGridPos().y() * yLength + yLength / 2));
    QPoint requestPos(ghost->getGridPos().x(), ghost->getGridPos().y());
    if(ghost->getState() == Avatar::up){
        requestPos.ry()--;
    }
    if(ghost->getState() == Avatar::down){
        requestPos.ry()++;
    }
    if(ghost->getState() == Avatar::left){
        requestPos.rx()--;
    }
    if(ghost->getState() == Avatar::right){
        requestPos.rx()++;
    }
    ghost->setGridPos(requestPos);
    if(pacMan->getGridPos() == ghost->getGridPos()){
        ghostGetPacMan();
    }
    timerGhost->start(ANIMATION_TIME_MS);
}

