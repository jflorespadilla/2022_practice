#include "..\headers\Game.h"

Game::Game() {
	_quit = false;
}

Game::~Game() {

}

void Game::run() {
	if (_character.get() == NULL) {
		createCharacter();
	}

	char input;
	srand(time(NULL));
	while (!_quit) {
		std::cout << "Your character is " << _character->getName() << std::endl <<std::endl; 
		runActionSequence();
		std::cout << "Quit? (Y/N): ";
		std::cin >> input;
		if (input == 'y' || input == 'Y') {
			_quit = true;
		}
	}
}

void Game::createCharacter() {
	std::string name, ability;
	int health, defense, attackDamage;

	std::cout << "Create your character!\nName: ";
	std::cin >> name;
	std::cout << "Ability: ";
	std::cin >> ability;
	std::cout << "Health: ";
	std::cin >> health;
	std::cout << "Defense: ";
	std::cin >> defense;
	std::cout << "Attack Damage: ";
	std::cin >> attackDamage;

	std::cout << "Creating Hero Character..." << std::endl << std::endl;
	_character.reset(new hero(name, ability, health, defense, attackDamage));
}

void Game::runCombat() {
	generateEnemies();
	char input;
	int roll, diceSize=20;

	std::cout << "-----COMBAT ENTERED!!!-----" << std::endl << std::endl;

	///
	/// I am goint to seriously need to rework this logic.
	/// They way I want this to work now has me needing to create 
	/// new functions. Perhaps even new classes.
	/// 
	
	while (_character->checkIfAlive() && targetEnemy.checkIfAlive()) {
		roll = rollDice(diceSize);

		std::cout << "Your Health: " << _character->getHealth() << "\nEnemy Health: " << targetEnemy.getHealth() << std::endl << std::endl;
		std::cout << "Attack? (Y/N): ";
		std::cin >> input;
		switch (input) {
		case 'y':
		case 'Y':
			_character->attackCharacter(targetEnemy, roll);
			break;
		}

		if (targetEnemy.checkIfAlive()) {
			combatEnemyAttackCharacter(_character.get(), &targetEnemy, diceSize);
		}
		else {
			std::cout << "You've conqured your enemy!!" << std::endl << std::endl;
			return;
		}

		if (character->checkIfAlive()) {
			std::cout << "Continue combat? (Y/N) ";
			std::cin >> input;
			if (input == 'N' || input == 'n') {
				std::cout << "You have fled combat!" << std::endl << std::endl;
				return;
			}
		}
		else {
			std::cout << "Your enemy has vanqueshed you!!" << std::endl << std::endl;
			return;
		}
	}
}

void Game::runActionSequence() {
	if (_gameMap.get() == NULL) {
		std::string mapFile = "maps/testmap.txt";
		generateGameMap(mapFile);
	}
	Cursor playerCursor;
	_gameMap->getPlayerCoordinates(playerCursor);
	std::cout << "Character is at coordinate: (" << playerCursor.x << ", " << playerCursor.y << ")\n";

	std::cout << "Navigate? (WASD)" << std::endl << std::endl;
	char input;
	std::cin >> input;

	switch (input) {
	case 'w':
	case 'W':
		_gameMap->updatePlayerCoordinates(0, 1);
		break;
	case 's':
	case 'S':
		_gameMap->updatePlayerCoordinates(0, -1);
		break;
	case 'a':
	case 'A':
		_gameMap->updatePlayerCoordinates(-1, 0);
		break;
	case 'd':
	case 'D':
		_gameMap->updatePlayerCoordinates(1, 0);
		break;
	}
	_gameMap->getPlayerCoordinates(playerCursor);
	std::cout << "Character is at coordinate: (" << playerCursor.x << ", " << playerCursor.y << ")\n";
	if (_gameMap->hasEnemies()) {
		std::cout << "Enemy Located! \n";
	}
}

void Game::combatEnemyAttackCharacter(hero* mc, Enemy* enemy, int diceSize) {
	int roll;
	if (rollDice(100) > 60) {
		roll = rollDice(diceSize);
		enemy->attackCharacter(mc, roll);
	}
	else {
		std::cout << "Enemy hesitates and hisses at you" << std::endl << std::endl;
	}
}

int Game::rollDice(int diceSize) {
	int roll;
	roll = rand() % diceSize + 1;
	return roll;
}

void Game::generateGameMap(std::string mapFile) {
	_gameMap.reset(new GameMap(mapFile));
}

void Game::gameOver() {
	char input;
	std::cout << "Game Over.\nTry Again?\n(Y/N): ";
	std::cin >> input;
	if (input == 'n' || input == 'N') {
		_quit = true;
		return;
	}
	_character->revive();
}

void Game::generateEnemies() {
	
}