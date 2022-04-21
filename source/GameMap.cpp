#include "..\headers\GameMap.h"

GameMap::GameMap(int x, int y) {
    std::srand(std::time(nullptr));
    yMax = y;
    xMax = x;
    _coordinateCells.resize(yMax * xMax);
    
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
        _coordinateCells.push_back(cell);

        if (75 < (rand() % 100)) {
            _enemyCoordinate = std::pair<int, int>(xCoord, yCoord);
            _enemyCoordinates.push_back(_enemyCoordinate);
        }

        if (xCoord < xMax) {
            xCoord++;
        }
        else if (yCoord < yMax) {
            xCoord = 0;
            yCoord++;
        }
    }
    _playerCursor.x = xMax / 2;
    _playerCursor.y = yMax / 2;
}

GameMap::GameMap(std::string fileName) {
    std::ifstream mapFile;
    CoordinateCell cell;
    int terrainSelector;
    std::srand(std::time(nullptr));

    mapFile.open(fileName);
    if (mapFile.is_open()) {
        mapFile >> xMax;
        mapFile >> yMax;
        _coordinateCells.resize(yMax * xMax);
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
            _coordinateCells.push_back(cell);
            if (75 < (rand() % 100)) {
                _enemyCoordinate = std::pair<int, int>(cell.x, cell.y);
                _enemyCoordinates.push_back(_enemyCoordinate);
            }
        }
        mapFile.close();
    }
    else {
        xMax = 4;
        yMax = 4;

        int xCoord = 0;
        int yCoord = 0;
        CoordinateCell cell;
        _coordinateCells.resize(yMax * xMax);

        for (int i = 0; i < yMax * xMax; i++) {
            cell.y = yCoord;
            cell.x = xCoord;
            cell.terrain = mountain;

            _coordinateCells.push_back(cell);
            if (75 < (rand() % 100)) {
                _enemyCoordinate = std::pair<int, int>(xCoord, yCoord);
                _enemyCoordinates.push_back(_enemyCoordinate);
            }

            if (xCoord < xMax) {
                xCoord++;
            }
            else if (yCoord < yMax) {
                xCoord = 0;
                yCoord++;
            }
        }
    }
    _playerCursor.x = xMax / 2;
    _playerCursor.y = yMax / 2;
}

GameMap::~GameMap() {
    
}

void GameMap::getPlayerCoordinates(Cursor& cursor) {
    cursor.x = _playerCursor.x;
    cursor.y = _playerCursor.y;
}

void GameMap::updatePlayerCoordinates(int x, int y) {
    _playerCursor.x += x;
    _playerCursor.y += y;

    if (_playerCursor.x >= xMax) {
        _playerCursor.x = xMax - 1;
    }

    if (_playerCursor.y >= yMax) {
        _playerCursor.y = yMax - 1;
    }

    if (_playerCursor.x < 0) {
        _playerCursor.x = 0;
    }

    if (_playerCursor.y < 0) {
        _playerCursor.y = 0;
    }
}

int GameMap::getArea() {
    return yMax * xMax;
}

bool GameMap::hasEnemies() {
    std::vector<std::pair<int, int>>::iterator itr;

    for (itr = _enemyCoordinates.begin(); itr < _enemyCoordinates.end(); itr++) {
        if (itr->first == _playerCursor.x && itr->second == _playerCursor.y) {
            return true;
        }
    }

    return false;
}
