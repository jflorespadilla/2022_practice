#include "..\headers\GameMap.h"

GameMap::GameMap(int x, int y) {
    yMax = y;
    xMax = x;
    coordinateCells.resize(yMax * xMax);
    
    // Generate Default Map
        // Loop iteratively
        // Set the coordinates
}

GameMap::~GameMap() {
    
}

int GameMap::getArea() {
    return yMax * xMax;
}
