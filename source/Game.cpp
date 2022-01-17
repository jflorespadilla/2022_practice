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
		std::cout << "Game is running. Press Q to Quit" << std::endl << std::endl;
		std::cin >> input;
		if (input == 'q' || input == 'Q') {
			quit = true;
		}
	}
}

void Game::createCharacter() {
	std::cout << "This is the create character function" << std::endl << std::endl;
}
