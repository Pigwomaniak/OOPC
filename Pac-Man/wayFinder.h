//
// Created by maciek on 17/01/2020.
//

#pragma once

#include <vector>
#include <queue>
#include <QPoint>

#include "tile.h"
#include "avatar.h"

#define X_GRID_SIZE 28
#define Y_GRID_SIZE 31

class WayFinder {
public:
    enum Strategy {seek = 0, runAway = 1};

    WayFinder(std::vector<std::vector<Tile>>* newGrid, QPoint newGhostPos, QPoint destPoint);


 //   int findMovDirection(int strategy);
    Avatar::MoveState findMovDirection2(Strategy strategy);

private:
    QPoint getPacManPos();
    QPoint destinationPoint;
    QPoint ghostPos;
    std::vector<std::vector<Tile>> grid;
    std::queue<QPoint> neighbors;
    Avatar::MoveState DirLowCost(QPoint point);
    Avatar::MoveState DirHighCost(QPoint point);
    //stay = 0, right = 1, left = 2, up = 3, down = 4
    //int dx[5] = {0, -1, 1, 0, 0};
    //int dy[5] = {0, 0, 0, 1, -1};
    int dx[5] = {0, 1, -1, 0, 0};
    int dy[5] = {0, 0, 0, -1, 1};
};

