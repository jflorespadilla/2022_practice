#pragma once
#include <iostream>
#include <conio.h>
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
	void displayCharacterHealth();
	void displayEnemyHealth();
	void runCombat();
	void runActionSequence();
	void combatEnemyAttackCharacter(Enemy* enemy, int diceSize);
	void combatEnemiesAttack(int diceSize);
	int rollDice(int diceSize);
	void generateGameMap(std::string mapFile);
	void gameOver();
	void generateEnemies();
	bool allEnemiesVanquished();
	char getInput();
	void promptQuit();

private:
	bool _quit;
	std::shared_ptr<hero> _character;
	std::vector<Enemy*> _enemies;
	std::shared_ptr<GameMap> _gameMap;
};

