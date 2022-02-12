#include "..\headers\Game.h"

Game::Game() {
	quit = false;
}

Game::~Game() {

}

void Game::run() {
	if (character.get() == NULL) {
		createCharacter();
	}

	char input;
	srand(time(NULL));
	while (!quit) {
		std::cout << "Your character is " << character->getName() << std::endl <<std::endl; 

		Enemy enemy("Lizard", "Slash", 12, 4);
		std::cout << "Your enemy is " << enemy.getName() << std::endl << std::endl;

		std::cout << "Enter Combat?\nY) Yes\nN) No" << std::endl;
		std::cin >> input;

		if (input == 'y' || input == 'Y') {
			runCombat(enemy);
		}
		gameOver();
	}
}

void Game::createCharacter() {
	std::cout << "This is the create character function" << std::endl << std::endl;
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
	character.reset(new hero(name, ability, health, defense, attackDamage));
}

void Game::runCombat(Enemy& targetEnemy) {
	char input;
	int roll, diceSize=20;
	bool continueCombat = true;

	std::cout << "-----COMBAT ENTERED!!!-----" << std::endl << std::endl;

	while (character->checkIfAlive() && targetEnemy.checkIfAlive() && continueCombat) {
		roll = rollDice(diceSize);
		std::cout << roll << std::endl;

		std::cout << "Your Health: " << character->getHealth() << "\nEnemy Health: " << targetEnemy.getHealth() << std::endl << std::endl;
		std::cout << "Attack? (Y/N): ";
		std::cin >> input;
		switch (input) {
		case 'y':
		case 'Y':
			character->attackCharacter(targetEnemy, roll);
			break;
		}

		if (rollDice(100) > 60) {
			roll = rollDice(diceSize);
			targetEnemy.attackCharacter(character.get(), roll);
			std::cout << "Enemy has attacked you!" << std::endl << std::endl;
		}
		else {
			std::cout << "Enemy hesitates and hisses at you" << std::endl << std::endl;
		}

		std::cout << "Continue combat? (Y/N) ";
		std::cin >> input;

		if (input == 'N' || input == 'n') {
			continueCombat = false;
		}
	}

	if (character->checkIfAlive() && continueCombat) {
		std::cout << "You've conqured your enemy!!" << std::endl << std::endl;
	}
	else if (targetEnemy.checkIfAlive() && continueCombat) {
		std::cout << "Your enemy has vanqueshed you!!" << std::endl << std::endl;
	}
	else {
		std::cout << "You have fled combat!" << std::endl << std::endl;
	}
}

int Game::rollDice(int diceSize) {
	int roll;
	std::cout << "Rolling dice!\nRoll: ";
	roll = rand() % diceSize + 1;
	return roll;
}

void Game::gameOver() {
	char input;
	std::cout << "Game Over.\nTry Again?\n(Y/N): ";
	std::cin >> input;
	if (input == 'n' || input == 'N') {
		quit = true;
		return;
	}
	character->revive();
}
