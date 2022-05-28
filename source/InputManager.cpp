#include "../headers/InputManager.h"

InputManager::InputManager(HANDLE& hStdin, DWORD& fdwSaveOldMode) {
	_hStdin = hStdin;
	_fdwSaveOldMode = fdwSaveOldMode;
}

InputManager::~InputManager() {

}

char InputManager::GetKey() {
	// set the input handle

	// Iterate over events
		// Store key states
	// Return released keys
	return 0; // Stub return
}


