#pragma once
#include <vector>

enum Terrain_Type {sand, stone, grass, swamp, marsh, forrest, jungle, mountain};

struct CoordinateCell {
	int x, y;
	Terrain_Type terrain;
};

class GameMap {
	public:
		GameMap(int x=10, int y=10);
		~GameMap();
		int getArea();

	private:
		int yMax, xMax;
		std::vector<CoordinateCell> coordinateCells;
};


