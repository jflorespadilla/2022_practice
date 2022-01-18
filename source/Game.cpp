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
	while (!quit) {
		std::cout << "Your character is " << character->getName() << std::endl <<std::endl; 

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
