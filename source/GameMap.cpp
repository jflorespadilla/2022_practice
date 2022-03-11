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
    playerCursor.x = xMax / 2;
    playerCursor.y = yMax / 2;
}

GameMap::GameMap(std::string fileName) {
    std::ifstream mapFile;
    CoordinateCell cell;
    int terrainSelector;

    mapFile.open(fileName);
    if (mapFile.is_open()) {
        mapFile >> xMax;
        mapFile >> yMax;
        coordinateCells.resize(yMax * xMax);
        while (mapFile.good()) {
            mapFile >> cell.x;
            mapFile >> cell.y;
            mapFile >> terrainSelector;

            switch (terrainSelector) {
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
        }
        mapFile.close();
    }
    else {
        xMax = 4;
        yMax = 4;

        int xCoord = 0;
        int yCoord = 0;
        CoordinateCell cell;
        coordinateCells.resize(yMax * xMax);

        for (int i = 0; i < yMax * xMax; i++) {
            cell.y = yCoord;
            cell.x = xCoord;
            cell.terrain = mountain;

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
    playerCursor.x = xMax / 2;
    playerCursor.y = yMax / 2;
}

GameMap::~GameMap() {
    
}

void GameMap::getPlayerCoordinates(Cursor& cursor) {
    cursor.x = playerCursor.x;
    cursor.y = playerCursor.y;
}

void GameMap::updatePlayerCoordinates(int x, int y) {
    playerCursor.x += x;
    playerCursor.y += y;

    if (playerCursor.x >= xMax) {
        playerCursor.x = xMax - 1;
    }

    if (playerCursor.y >= yMax) {
        playerCursor.y = yMax - 1;
    }

    if (playerCursor.x < 0) {
        playerCursor.x = 0;
    }

    if (playerCursor.y < 0) {
        playerCursor.y = 0;
    }
}

int GameMap::getArea() {
    return yMax * xMax;
}
