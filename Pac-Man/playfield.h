//
// Created by maciek on 15/01/2020.
//

#pragma once

#include <QWidget>
#include <QTimer>
#include "grid.h"
#include "avatar.h"
#include "ghostSpeeder.h"
#include "wayFinder.h"
#include "ghostAmbush.h"

#define ANIMATION_TIME_MS 20
#define GHOST_SPEED 200
#define BOOST_TIME 8000

class PlayField
        : public QWidget{
Q_OBJECT

public:
    PlayField(QWidget *parent = nullptr);
    void newGame();


public slots:

    void movPacManUp();
    void movPacManDown();
    void movPacManRight();
    void movPacManLeft();
    //void timeToMovGhostSpeeder(){movAvatar(ghostSpeeder, timerGhostSpeeder);};
private slots:
    void movAvatar(Avatar* avatar, QTimer* timer);
    void timeToMovPacMan(){movAvatar(pacMan, timerPacMan);};
    void timeToMoveGhostSpeeder(){movAvatar(ghostSpeeder, timerGhostSpeeder);};
    void timeToMoveGhostAmbush(){movAvatar(ghostAmbush, timerGhostAmbush);};
    void timeToMoveGhosts();
    void ghostGetPacMan(){newGame();};
    void boostEnd();

signals:
    void getPoint();
protected:
    void paintEvent(QPaintEvent *event);
    void paintPoints();
    void paintAvatar(Avatar* avatar);
    void paintWalls();
    void movGhost(GhostSpeeder* ghost, QTimer* timerGhost);


private:
    //QPixmap* pixMap;
    Grid* grid;
    Avatar* pacMan;

    GhostSpeeder* ghostSpeeder;
    GhostAmbush* ghostAmbush;
    void pointCheck(QPoint toCheckPoint);

    QTimer* timerPacMan;
    QTimer* timerBoost;
    QTimer* ghostTimer;
    QTimer* timerGhostSpeeder;
    QTimer* timerGhostAmbush;
    WayFinder::Strategy strategy;

};


