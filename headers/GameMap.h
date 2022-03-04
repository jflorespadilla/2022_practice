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
		int getArea();

	private:
		int yMax, xMax;
		std::vector<CoordinateCell> coordinateCells;
		Cursor playerCursor;
};


