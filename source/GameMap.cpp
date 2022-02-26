#include "..\headers\GameMap.h"

GameMap::GameMap(int x, int y) {
    yMax = y;
    xMax = x;
    coordinateCells.resize(yMax * xMax);
    
    // Generate Default Map
    int xCoord = 0;
    int yCoord = 0;
    CoordinateCell cell;
    
    for (int cellCount = 0; cellCount < yMax * xMax; cellCount++) {
        cell.x = xCoord;
        cell.y = yCoord;
        switch (cellCount % 8) {
        case 0:
            cell.terrain = sand;
            break;
        case 1:
            cell.terrain = stone;
            break;
        case 2:
            cell.terrain = grass;
            break;
        case 3:
            cell.terrain = swamp;
            break;
        case 4:
            cell.terrain = marsh;
            break;
        case 5:
            cell.terrain = forrest;
            break;
        case 6:
            cell.terrain = jungle;
            break;
        case 7:
            cell.terrain = mountain;
            break;
        }
        coordinateCells.push_back(cell);

        if (xCoord < xMax) {
            xCoord++;
        }
        else if (yCoord < yMax) {
            xCoord = 0;
            yCoord++;
        }
    }
}

GameMap::~GameMap() {
    
}

int GameMap::getArea() {
    return yMax * xMax;
}
