#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Character.h"
#include "hero.h"
#include "Enemy.h"
#include <stdlib.h>
#include <time.h>

class Game {
public:
	Game();
	~Game();
	void run();
	void createCharacter();
	void runCombat(Enemy& targetEnemy);
	int rollDice(int diceSize);
	void gameOver();

private:
	bool quit;
	std::shared_ptr<hero> character;
	std::vector<Enemy> enemies;

};

