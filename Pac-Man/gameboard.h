//
// Created by maciek on 14/01/2020.
//

#pragma once

#include <QWidget>
#include <QLCDNumber>

class PlayField;


class GameBoard : public QWidget
{
Q_OBJECT

public:
    GameBoard(QWidget *parent = 0);
public slots:
    void newGame();

protected slots:
    void getPoint();
    void getBigPoint();
    void newHighScore();
    void pacManKilled();

private:
    QLCDNumber *scoreLCD;
    QLCDNumber *highScoreLCD;
    QLCDNumber *livesLCD;
    PlayField *playField;
    int collectedSmallPoint;
};
