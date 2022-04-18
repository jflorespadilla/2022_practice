#pragma once
#include <string>
#include <vector>
#include <fstream>

enum Terrain_Type {sand, stone, grass, swamp, marsh, forrest, jungle, mountain};

struct CoordinateCell {
	int x, y;
	Terrain_Type terrain;
};

struct Cursor {
	int x,y;
};

class GameMap {
	public:
		GameMap(int x=10, int y=10);
		GameMap(std::string fileName);
		~GameMap();
		void getPlayerCoordinates(Cursor& cursor);
		void updatePlayerCoordinates(int x, int y);
		int getArea();
		bool hasEnemies();

	private:
		int yMax, xMax;
		std::vector<CoordinateCell> coordinateCells;
		Cursor playerCursor;
};


