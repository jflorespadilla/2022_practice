#include "../headers/InputManager.h"

InputManager::InputManager(HANDLE& hStdin, DWORD& fdwSaveOldMode) {
	_hStdin = hStdin;
	_fdwSaveOldMode = fdwSaveOldMode;
}

InputManager::~InputManager() {

}

// Gutting the input class. Going to study up and make some simple functions first.
