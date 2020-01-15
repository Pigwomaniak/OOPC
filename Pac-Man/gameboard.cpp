//
// Created by maciek on 14/01/2020.
//
#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QShortcut>
#include <QVBoxLayout>
#include <QWidget>

#include "gameboard.h"
#include "playfield.h"


GameBoard::GameBoard(QWidget *parent)
        : QWidget(parent) {

    //Quit
    QPushButton *quit = new QPushButton(tr("&Quit"), this);
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    //New Game
    QPushButton *newGame = new QPushButton(tr("&New Game"), this);
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(newGame, SIGNAL(clicked()), this, SLOT(newGame()));

    //Score
    scoreLCD = new QLCDNumber(2, this);
    scoreLCD->setSegmentStyle(QLCDNumber::Filled);

    QLabel *scoreLabel = new QLabel(tr("SCORE"), this);
    QVBoxLayout *scoreLayout = new QVBoxLayout;
    scoreLayout->addWidget(scoreLabel);
    scoreLayout->addWidget(scoreLCD);
    //need connect

    //High Score
    highScoreLCD = new QLCDNumber(2, this);
    highScoreLCD->setSegmentStyle(QLCDNumber::Filled);
    highScoreLCD->setWindowTitle(tr("High Score"));
    QLabel *highScoreLabel = new QLabel(tr("HIGH SCORE"), this);
    QVBoxLayout* highScoreLayout = new QVBoxLayout;
    highScoreLayout->addWidget(highScoreLabel);
    highScoreLayout->addWidget(highScoreLCD);

    //Top Layout
    QHBoxLayout* topLayout = new QHBoxLayout;
    topLayout->addWidget(newGame);
    topLayout->addLayout(scoreLayout);
    topLayout->addLayout(highScoreLayout);
    topLayout->addWidget(quit);

    //Bottom Layout
    // życia i wiśenki
    QHBoxLayout* bottomLayout = new QHBoxLayout;


    playField = new PlayField(this);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(playField);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);
}

void GameBoard::newGame() {

}

void GameBoard::newHighScore() {

}

void GameBoard::getPoint() {

}
