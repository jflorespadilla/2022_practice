#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Character.h"
#include "hero.h"
#include "Enemy.h"

class Game {
public:
	Game();
	~Game();
	void run();
	void createCharacter();

private:
	bool quit;
	std::shared_ptr<Character> character;
	std::vector<Enemy> enemies;

};

