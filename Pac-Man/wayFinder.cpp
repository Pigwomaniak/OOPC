//
// Created by maciek on 17/01/2020.
//

#include "wayFinder.h"

WayFinder::WayFinder(std::vector<std::vector<Tile>> *newGrid, QPoint newGhostPos, QPoint destPoint) {
    grid = *newGrid;
    //pacManPos();
    ghostPos = newGhostPos;
    grid[ghostPos.y()][ghostPos.x()].ghost = true;
    destinationPoint = destPoint;
}

QPoint WayFinder::getPacManPos() {
    for (int i = 0; i < Y_GRID_SIZE; ++i) {
        for (int j = 0; j < X_GRID_SIZE; ++j) {
            if(grid[i][j].pacMan){
                //grid[i][j].wayPointNbr = 0;
                return QPoint(j, i);
            }
        }
    }
    return QPoint(0, 0);
}

int WayFinder::findMovDirection(int strategy) {
    QPoint pacManPos = getPacManPos();
    neighbors.push(pacManPos);
    grid[pacManPos.y()][pacManPos.x()].wayPointNbr = 0;

    while (!neighbors.empty()){
        QPoint current = neighbors.front();
        neighbors.pop();
        int currentCost = grid[current.y()][current.x()].wayPointNbr + 1;
        for (int i = 1; i < 5; ++i) {
            int x = current.x() + dx[i];
            int y = current.y() + dy[i];
            if((x < 0) || (x >= X_GRID_SIZE) || (y < 0) || (y >= Y_GRID_SIZE)) break;
            if(grid[y][x].wall) break;
            if(grid[y][x].ghost){
                return i;
            }
            if(grid[x][y].wayPointNbr < currentCost) break;
            grid[x][y].wayPointNbr = currentCost;
            neighbors.push(QPoint(x, y));

        }
    }
}


Avatar::MoveState WayFinder::findMovDirection2(Strategy strategy) {
    //QPoint destinationPoint = getPacManPos();
    if(destinationPoint == ghostPos) return Avatar::stay;
    neighbors.push(destinationPoint);
    grid[destinationPoint.y()][destinationPoint.x()].wayPointNbr = 0;

    while (!neighbors.empty()){
        QPoint current = neighbors.front();
        neighbors.pop();
        int currentCost = grid[current.y()][current.x()].wayPointNbr + 1;
        for (int i = 1; i < 5; ++i) {
            int x = current.x() + dx[i];
            int y = current.y() + dy[i];
            if((x < 0) || (x >= X_GRID_SIZE) || (y < 0) || (y >= Y_GRID_SIZE)) break;
            if(grid[y][x].wall) break;
            if(grid[x][y].wayPointNbr < currentCost) break;
            grid[x][y].wayPointNbr = currentCost;
            neighbors.push(QPoint(x, y));

        }
    }
    if(strategy == runAway) return DirHighCost(ghostPos);
    if(strategy == seek) return DirLowCost(ghostPos);

}

Avatar::MoveState WayFinder::DirLowCost(QPoint point) {
    int min = 1000;
    Avatar::MoveState way = Avatar::stay;
    for (int i = 0; i < 5; ++i) {
        int x = point.x() + dx[i];
        int y = point.y() + dy[i];
        if(grid[y][x].wayPointNbr < min){
            min = grid[y][x].wayPointNbr;
            way = (Avatar::MoveState)i;
        }
    }
    return way;
}

Avatar::MoveState WayFinder::DirHighCost(QPoint point) {
    int max = 0;
    Avatar::MoveState way = Avatar::stay;
    for (int i = 0; i < 5; ++i) {
        int x = point.x() + dx[i];
        int y = point.y() + dy[i];
        if(grid[y][x].wayPointNbr > max){
            max = grid[y][x].wayPointNbr;
            way = (Avatar::MoveState)i;
        }
    }
    return way;
}
