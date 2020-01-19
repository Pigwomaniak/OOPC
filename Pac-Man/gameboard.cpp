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
    connect(playField, SIGNAL(pacManKilled()), this, SLOT(pacManKilled()));
    connect(playField, SIGNAL(getBigPoint()), this, SLOT(getBigPoint()));

    //Quit
    QPushButton *quit = new QPushButton(tr("&Quit"), this);
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    //New Game
    QPushButton *newGame = new QPushButton(tr("&New Game"), this);
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(newGame, SIGNAL(clicked()), this, SLOT(newGame()));

    //Score
    scoreLCD = new QLCDNumber(3, this);
    scoreLCD->setSegmentStyle(QLCDNumber::Filled);

    QLabel *scoreLabel = new QLabel(tr("SCORE"), this);
    scoreLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *scoreLayout = new QVBoxLayout;
    scoreLayout->addWidget(scoreLabel);
    scoreLayout->addWidget(scoreLCD);
    connect(playField, SIGNAL(getPoint()), this, SLOT(getPoint()));

    //High Score
    highScoreLCD = new QLCDNumber(3, this);
    highScoreLCD->setSegmentStyle(QLCDNumber::Filled);
    highScoreLCD->setWindowTitle(tr("High Score"));
    QLabel *highScoreLabel = new QLabel(tr("HIGH SCORE"), this);
    highScoreLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout* highScoreLayout = new QVBoxLayout;
    highScoreLayout->addWidget(highScoreLabel);
    highScoreLayout->addWidget(highScoreLCD);

    //Lives
    livesLCD = new QLCDNumber(1, this);
    livesLCD->setSegmentStyle(QLCDNumber::Filled);
    QLabel* livesLabel = new QLabel(tr("LIVES"), this);
    QHBoxLayout* bottomLayout = new QHBoxLayout;
    QVBoxLayout* livesLayout = new QVBoxLayout;
    livesLayout->addWidget(livesLabel);
    livesLayout->addWidget(livesLCD);


    //Top Layout
    QHBoxLayout* topLayout = new QHBoxLayout;
    topLayout->addWidget(newGame);
    topLayout->addLayout(scoreLayout);
    topLayout->addLayout(highScoreLayout);
    topLayout->addLayout(livesLayout);
    topLayout->addWidget(quit);

    //Bottom Layout
    // życia i wiśenki
    /*
    livesLCD = new QLCDNumber(1, this);
    livesLCD->setSegmentStyle(QLCDNumber::Filled);
    QLabel* livesLabel = new QLabel(tr("LIVES"), this);
    QHBoxLayout* bottomLayout = new QHBoxLayout;
    QVBoxLayout* livesLayout = new QVBoxLayout;
    livesLayout->addWidget(livesLabel);
    livesLayout->addWidget(livesLCD);
    bottomLayout->addLayout(livesLayout);
    //bottomLayout->setGeometry(QRect(0,height() - height() / 12, width(), height()));
    bottomLayout->setContentsMargins(0,height()/12, width(), 0);
*/



    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(playField);
    //mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);

    (void) new QShortcut(Qt::Key_W, playField, SLOT(movPacManUp()));
    (void) new QShortcut(Qt::Key_S, playField, SLOT(movPacManDown()));
    (void) new QShortcut(Qt::Key_D, playField, SLOT(movPacManRight()));
    (void) new QShortcut(Qt::Key_A, playField, SLOT(movPacManLeft()));



}

void GameBoard::newGame() {
    scoreLCD->display(0);
    playField->newGame();
    collectedSmallPoint = 0;
    livesLCD->display(3);
}

void GameBoard::newHighScore() {
    highScoreLCD->display(scoreLCD->intValue());
}

void GameBoard::getPoint() {
    scoreLCD->display(scoreLCD->intValue() + 1);
    if(scoreLCD->intValue() >= highScoreLCD->intValue()){
        newHighScore();
    }
    if(++collectedSmallPoint == 240){
        newGame();
    }
}

void GameBoard::getBigPoint() {
    scoreLCD->display(scoreLCD->intValue() + 10);
}

void GameBoard::pacManKilled() {
    if(livesLCD->intValue() > 0){
        livesLCD->display(livesLCD->intValue() - 1);
    } else{
        playField->endGame();
    }
}
