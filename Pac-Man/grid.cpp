//
// Created by maciek on 15/01/2020.
//

#include "grid.h"

Grid::Grid() {
    for (int i = 0; i < Y_GRID_SIZE; ++i) {
        std::vector<Tile> line;
        for (int j = 0; j < X_GRID_SIZE; ++j) {
            line.push_back(Tile());
        }
        grid.push_back(line);
    }
}

void Grid::newGame() {
    for (int i = 0; i < Y_GRID_SIZE; ++i) {
        for (int j = 0; j < X_GRID_SIZE; ++j) {
            if(walls[i][j] == 1) grid[i][j].wall = true;
            if(walls[i][j] == 2) grid[i][j].smallPoint = true;
            if(walls[i][j] == 4) grid[i][j].ghost = true;
            if(walls[i][j] == 6) grid[i][j].bigPoint = true;
        }
    }
}

bool Grid::movCheck(QPoint pointToCheck) {
    if((pointToCheck.x() < 0 || pointToCheck.x() >= X_GRID_SIZE) || ((pointToCheck.y() < 0 || pointToCheck.y() >= Y_GRID_SIZE))) return false;
    Tile* tileToCheck = &grid[pointToCheck.y()][pointToCheck.x()];
    if(tileToCheck->wall) return false;
    return true;
}

bool Grid::checkSmallPoint(QPoint point) {
    if(grid[point.y()][point.x()].smallPoint){
        grid[point.y()][point.x()].smallPoint = false;
        return true;
    }
    return false;
}
