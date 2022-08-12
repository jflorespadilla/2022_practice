#include "..\headers\Game.h"

Game::Game() {
	_quit = false;
	_inputManager = new InputManager();
}

Game::~Game() {

}

void Game::run() {
	if (_character.get() == NULL) {
		createCharacter();
		std::cout << "Your character is " << _character->getName() << std::endl << std::endl;
	}

	srand(time(NULL));
	while (!_quit) {
		runActionSequence();
		gameOver();
	}
}

void Game::createCharacter() {
	std::string name, ability;
	int health, defense, attackDamage;

	std::cout << "Create your character!\nName: ";
	name = _inputManager->GetLine();
	std::cout << "Ability: ";
	ability = _inputManager->GetLine();
	std::cout << "Health: ";
	health = _inputManager->GetInt();
	std::cout << "Defense: ";
	defense = _inputManager->GetInt();
	std::cout << "Attack Damage: ";
	attackDamage = _inputManager->GetInt();

	std::cout << "Creating Hero Character..." << std::endl << std::endl;
	_character.reset(new hero(name, ability, health, defense, attackDamage));
}

void Game::displayCharacterHealth() {
	std::cout << "Your Health: " << _character->getHealth() << "\n";
}

void Game::displayEnemyHealth() {
	std::vector<Enemy*>::const_iterator enemyIt;

	std::cout << "Enemy Health: ";

	for (enemyIt = _enemies.begin(); enemyIt != _enemies.end(); ++enemyIt) {
		if ((*enemyIt)->checkIfAlive()) {
			std::cout <<  (*enemyIt)->getHealth() << "\n";
		}
		else {
			std::cout << "Enemy is vanquished\n";
		}
	}
}

void Game::runCombat() {
	generateEnemies();
	int attackOption, roll, diceSize=20, attackOptions = 1;
	std::vector<Enemy*>::const_iterator enemyIt;

	std::cout << "-----COMBAT ENTERED!!!-----" << std::endl << std::endl;
	
	while (_character->checkIfAlive() && !allEnemiesVanquished()) {
		roll = rollDice(diceSize);

		displayCharacterHealth();
		displayEnemyHealth();

		std::cout << "Attack? (Y/N): ";
		switch (_inputManager->GetKey()) {
		case 'y':
		case 'Y':
			std::cout << "\n Attack Option:\n";
			for (enemyIt = _enemies.begin(); enemyIt != _enemies.end() ; ++enemyIt) {
				std::cout << attackOptions << ")" << (*enemyIt)->getName() << " \n";
				attackOptions++;
			}

			attackOption = _inputManager->GetInt();
			_character->attackCharacter(*_enemies[attackOption - 1], roll);
			break;
			// I think I need to rethink combat flow here
		case 'N':
		case'n':
			break;
		}

		combatEnemiesAttack(diceSize);

		if (_character->checkIfAlive()) {
			std::cout << "Continue combat? (Y/N) ";
			char promptAnswer = _inputManager->GetKey();
			if ( promptAnswer == 'N' || promptAnswer == 'n') {
				std::cout << "You have fled combat!" << std::endl << std::endl;
				return;
			}
		}
		else {
			std::cout << "Your enemies have vanqueshed you!!" << std::endl << std::endl;
			return;
		}
	}
	std::cout << "You have slain your foes!" << std::endl << std::endl;
}

void Game::runActionSequence() {
	if (_gameMap.get() == NULL) {
		std::string mapFile = "maps/testmap.txt";
		generateGameMap(mapFile);
	}
	Cursor playerCursor;

	while (!_quit && _character->checkIfAlive() ) {
		_gameMap->getPlayerCoordinates(playerCursor);
		std::cout << "Character is at coordinate: (" << playerCursor.x << ", " << playerCursor.y << ")\n";

		std::cout << "Navigate (WASD)" << std::endl << std::endl;

		switch (_inputManager->GetKey()) {
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

		if (_gameMap->hasEnemies()) {
			std::cout << "Enemy Located! \n";
			runCombat();
		}
	}
}

void Game::combatEnemyAttackCharacter(Enemy* enemy, int diceSize) {
	int roll;
	if (rollDice(100) > 60) {
		roll = rollDice(diceSize);
		enemy->attackCharacter(_character.get(), roll);
	}
	else {
		std::cout << "Enemy hesitates and hisses at you" << std::endl << std::endl;
	}
}

void Game::combatEnemiesAttack(int diceSize) {
	if (_enemies.empty()) {
		return;
	}

	for (int i = 0; i < _enemies.size(); i++) {
		if (_enemies[i]->checkIfAlive()) {
			combatEnemyAttackCharacter(_enemies[i], diceSize);
		}
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
	if (!_character->checkIfAlive()) {
		std::cout << "Game Over.\nTry Again?\n(Y/N): ";
		char promptAnswer = _inputManager->GetKey();
		if (promptAnswer == 'n' || promptAnswer == 'N') {
			_quit = true;
			return;
		}
		_character->revive();
	}
}

void Game::generateEnemies() {
	_enemies.clear();

	for (int i = 0; i < rand() % 57; i++) {
		_enemies.push_back(new Enemy());
	}
}

bool Game::allEnemiesVanquished() {
	bool retVal = true;

	if (_enemies.empty()) {
		return true;
	}

	for (int i = 0; i < _enemies.size(); i++) {
		retVal = (retVal && !_enemies[i]->checkIfAlive());
	}
	return retVal;
}

void Game::promptQuit() {
	std::cout << "\n\nAre you sure you want to quit? (Y/N): ";
	char promptResponse = _inputManager->GetKey();
	if ( promptResponse == 'y' || promptResponse == 'Y') {
		_quit = true;
		std::cout << "\n\nThank You for Playing! Bye!\n\n";
	}
}
