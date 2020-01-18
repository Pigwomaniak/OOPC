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
        if((destPoint.y() - FORWARD_LOOK) >= 0){
            if(grid->grid[destPoint.y() - FORWARD_LOOK][destPoint.x()].wall){
                destPoint.ry() -= FORWARD_LOOK;
            }
        }
    }
    if(actualMov == down){
        if((destPoint.y() + FORWARD_LOOK) < Y_GRID_SIZE){
            if(grid->grid[destPoint.y() + FORWARD_LOOK][destPoint.x()].wall){
                destPoint.ry() += FORWARD_LOOK;
            }
        }
    }
    if(actualMov == left){
        if((destPoint.x() - FORWARD_LOOK) >= 0){
            if(grid->grid[destPoint.y()][destPoint.x() - FORWARD_LOOK].wall){
                destPoint.rx() -= FORWARD_LOOK;
            }
        }
    }
    if(actualMov == right){
        if((destPoint.x() + FORWARD_LOOK) < X_GRID_SIZE){
            if(grid->grid[destPoint.y()][destPoint.x() + FORWARD_LOOK].wall){
                destPoint.rx() += FORWARD_LOOK;
            }
        }
    }
    return destPoint;
}


