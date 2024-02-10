#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Character.h"
#include "hero.h"
#include "Enemy.h"
#include "GameMap.h"
#include <time.h>
#include "InputManager.h"

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
	void promptQuit();

private:
	bool _quit;
	std::shared_ptr<hero> _character;
	std::vector<Enemy*> _enemies; //Why did I make this a vector of pointers?
	std::shared_ptr<GameMap> _gameMap;
	InputManager* _inputManager;
};

