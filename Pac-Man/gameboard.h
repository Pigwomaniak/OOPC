//
// Created by maciek on 14/01/2020.
//

#pragma once

#include <QWidget>

class GameBoard : public QWidget
{
Q_OBJECT

public:
    GameBoard(QWidget *parent = 0);

/*
protected slots:
    void fire();
    void hit();
    void missed();
    void newGame();


private:
    QLCDNumber *hits;
    QLCDNumber *shotsLeft;
    CannonField *cannonField;
*/
};
