//
// Created by maciek on 17/01/2020.
//

#pragma once

#include "avatar.h"
#include "wayFinder.h"
#include "tile.h"
#include <vector>
#include <QPoint>


class GhostSpeeder : public Avatar{
public:
    GhostSpeeder();
    virtual QPoint ghostDestPoint(Avatar* avatar);

protected:


};


