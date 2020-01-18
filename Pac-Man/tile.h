//
// Created by maciek on 15/01/2020.
//

#pragma once

class Tile {
public:
    Tile();

    bool smallPoint;
    bool bigPoint;
    bool wall;
    bool pacMan;
    bool ghostArea;
    bool way;
    bool ghost;
    int wayPointNbr;

};

