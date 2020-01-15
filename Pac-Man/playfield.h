//
// Created by maciek on 15/01/2020.
//

#pragma once

class QTimer;

class PlayField : public QWidget
{
Q_OBJECT

public:
    PlayField(QWidget *parent = 0);


public slots:
    void newGame();

private slots:

signals:


protected:
    void paintEvent(QPaintEvent *event);


private:
    QPixmap* pixMap;
};


