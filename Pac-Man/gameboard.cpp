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

    playField = new PlayField(this);

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
    connect(playField, SIGNAL(getPoint()), this, SLOT(getPoint()));

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




    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(playField);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);

    (void) new QShortcut(Qt::Key_W, this, SLOT(movPacManUp()));
    (void) new QShortcut(Qt::Key_S, this, SLOT(movPacManDown()));
    (void) new QShortcut(Qt::Key_D, this, SLOT(movPacManRight()));
    (void) new QShortcut(Qt::Key_A, this, SLOT(movPacManLeft()));
}

void GameBoard::newGame() {
    scoreLCD->display(0);
    playField->newGame();
}

void GameBoard::newHighScore() {
    highScoreLCD->display(scoreLCD->intValue());
}

void GameBoard::getPoint() {
    scoreLCD->display(scoreLCD->intValue() + 1);
    if(scoreLCD->intValue() >= highScoreLCD->intValue()){
        newHighScore();
    }
}

void GameBoard::movPacManUp() {
    playField->movPacManUp();
}

void GameBoard::movPacManDown() {
    playField->movPacManDown();
}

void GameBoard::movPacManRight() {
    playField->movPacManRight();
}

void GameBoard::movPacManLeft() {
    playField->movPacManLeft();
}
