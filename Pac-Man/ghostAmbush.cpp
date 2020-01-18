//
// Created by maciek on 18/01/2020.
//

#include "ghostAmbush.h"

GhostAmbush::GhostAmbush() {
    homePos = QPoint(13,14);
    gridPos =  QPoint(13,14);
    moveState = stay;
    color = Qt::blue;
}

QPoint GhostAmbush::ghostDestPoint(Avatar *avatar, Grid* grid) {
    QPoint destPoint = avatar->getGridPos();
    MoveState actualMov = avatar->getState();
    if(actualMov == up){
        if((destPoint.y() - 5) >= 0){
            if(grid->grid[destPoint.y() - 5][destPoint.x()].wall){
                destPoint.ry() -= 5;
            }
        }
    }
    if(actualMov == down){
        if((destPoint.y() + 5) < Y_GRID_SIZE){
            if(grid->grid[destPoint.y() + 5][destPoint.x()].wall){
                destPoint.ry() += 5;
            }
        }
    }
    if(actualMov == left){
        if((destPoint.x() - 5) >= 0){
            if(grid->grid[destPoint.y()][destPoint.x() - 5].wall){
                destPoint.rx() -= 5;
            }
        }
    }
    if(actualMov == right){
        if((destPoint.x() + 5) < X_GRID_SIZE){
            if(grid->grid[destPoint.y()][destPoint.x() + 5].wall){
                destPoint.rx() += 5;
            }
        }
    }
    return destPoint;
}


