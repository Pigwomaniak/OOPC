//
// Created by maciek on 18/01/2020.
//
#pragma once

#include <QPoint>
#include "ghostSpeeder.h"
#include "grid.h"

class GhostAmbush : public GhostSpeeder{
public:
    GhostAmbush();
    QPoint ghostDestPoint(Avatar* avatar, Grid* grid);
};


