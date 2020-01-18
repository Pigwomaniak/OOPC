//
// Created by maciek on 15/01/2020.
//

#pragma once

#include <QWidget>
#include <QTimer>
#include "grid.h"
#include "avatar.h"
#include "ghostSpeeder.h"

#define ANIMATION_TIME_MS 20

class PlayField
        : public QWidget{
Q_OBJECT

public:
    PlayField(QWidget *parent = 0);
    void newGame();


public slots:

    void movPacManUp();
    void movPacManDown();
    void movPacManRight();
    void movPacManLeft();
    void timeToMovGhostSpider(){movAvatar(ghostSpeeder, timerGhostSpeeder);};
private slots:
    void movAvatar(Avatar* avatar, QTimer* timer);
    void timeToMovPacMan(){movAvatar(pacMan, timerPacMan);};
    void timeToMoveGhostSpeeder(){movAvatar(ghostSpeeder, timerGhostSpeeder);};
    void timeToMoveGhosts();

signals:
    void getPoint();
protected:
    void paintEvent(QPaintEvent *event);
    void paintPoints();
    void paintAvatar(Avatar* avatar);
    void paintWalls();


private:
    QPixmap* pixMap;
    Grid* grid;
    Avatar* pacMan;

    GhostSpeeder* ghostSpeeder;
    void pointCheck(QPoint toCheckPoint);
    QTimer* ghostTimer;
    QTimer* timerPacMan;
    QTimer* timerGhostSpeeder;

};


