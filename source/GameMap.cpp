#include "..\headers\GameMap.h"

GameMap::GameMap(int x, int y) {
    yMax = y;
    xMax = x;
    coordinateCells.resize(yMax * xMax);
    
    // Generate Default Map
    for (int cellCount = 0; cellCount < yMax * xMax; cellCount++) {
        coordinateCells[cellCount].x = 1; // stub input. Need to figure out a way to insert correct coordinate value
        coordinateCells[cellCount].y = 1; // stub input. Need to figure out a way to insert correct coordinate value
        coordinateCells[cellCount].terrain = Terrain_Type::cellCount % 8; // stub input. Need to figure out a way to insert correct coordinate value

    }
}

GameMap::~GameMap() {
    
}

int GameMap::getArea() {
    return yMax * xMax;
}
