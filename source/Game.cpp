#include "..\headers\Game.h"

Game::Game() {
	quit = false;
}

Game::~Game() {

}

void Game::run() {
	char input;
	while (!quit) {
		std::cout << "Game is running. Press Q to Quit" << std::endl << std::endl;
		std::cin >> input;
		if (input == 'q' || input == 'Q') {
			quit = true;
		}
	}
}
