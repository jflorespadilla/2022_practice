#include "..\headers\Game.h"

Game::Game() {
	quit = false;
}

Game::~Game() {

}

void Game::run() {
	srand(time(NULL));
	int roll;

	if (character.get() == NULL) {
		createCharacter();
	}

	char input;
	while (!quit) {
		std::cout << "Your character is " << character->getName() << std::endl <<std::endl; 

		Enemy enemy;
		std::cout << "Your enemy is " << enemy.getName() << std::endl << std::endl;

		std::cout << "Enter Combat?\nY) Yes\nN) No" << std::endl;
		std::cin >> input;

		if (input == 'y' || input == 'Y') {
			std::cout << "-----COMBAT ENTERED!!!-----" << std::endl << std::endl;

			while (character->checkIfAlive() && enemy.checkIfAlive()) {
				std::cout << "Rolling dice!\nRoll: ";
				roll = rand() % 20 + 1;

				std::cout << roll << std::endl;

				std::cout << "Your Health: " << character->getHealth() << "\nEnemy Health: " << enemy.getHealth() << std::endl << std::endl;

				if (roll >= 12) {
					character->attackCharacter(enemy);
					std::cout << "You attacked the enemy!!!" << std::endl << std::endl;
				}
				else {
					enemy.attackCharacter(character.get());
					std::cout << "Enemy has attacked you!" << std::endl << std::endl;
				}
			}
			if (character->checkIfAlive()) {
				std::cout << "You've conqured your enemy!!" << std::endl << std::endl;
			}
			else {
				std::cout << "Your enemy has vanqueshed you!!" << std::endl << std::endl;
			}
		}

		std::cout << "Game is running. Press Q to Quit" << std::endl << std::endl;
		std::cin >> input;
		if (input == 'q' || input == 'Q') {
			quit = true;
		}
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
