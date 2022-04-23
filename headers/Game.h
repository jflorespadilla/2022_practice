#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Character.h"
#include "hero.h"
#include "Enemy.h"
#include "GameMap.h"
#include <stdlib.h>
#include <time.h>

class Game {
public:
	Game();
	~Game();
	void run();
	void createCharacter();
	void runCombat(Enemy& targetEnemy);
	void runActionSequence();
	void combatEnemyAttackCharacter(hero* mc, Enemy* enemy, int diceSize);
	int rollDice(int diceSize);
	void generateGameMap(std::string mapFile);
	void gameOver();
	void generateEnemies();

private:
	bool _quit;
	std::shared_ptr<hero> _character;
	std::vector<Enemy*> _enemies;
	std::shared_ptr<GameMap> _gameMap;
};

