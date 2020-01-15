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



GameBoard::GameBoard(QWidget *parent)
        : QWidget(parent) {

    //Quit
    QPushButton *quit = new QPushButton(tr("&Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    //New Game
    QPushButton *newGame = new QPushButton(tr("&New Game"));
    quit->setFont(QFont("Times", 18, QFont::Bold));
    //need connect

    //Score
    QLCDNumber* scoreLCD = new QLCDNumber(2);
    scoreLCD->setSegmentStyle(QLCDNumber::Filled);
    //need connect

    //High Score
    QLCDNumber* highScoreLCD = new QLCDNumber(2);
    highScoreLCD->setSegmentStyle(QLCDNumber::Filled);
    highScoreLCD->setWindowTitle(tr("High Score"));

    //Top Layout
    QHBoxLayout* topLayout = new QHBoxLayout;
    topLayout->addWidget(newGame);
    topLayout->addWidget(scoreLCD);
    topLayout->addWidget(highScoreLCD);
    topLayout->addWidget(quit);

    //Bottom Layout
    // życia i wiśenki
    QHBoxLayout* bottomLayout = new QHBoxLayout;

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    //pole gry
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);
}
