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


	// Late night code marker
	for (int i = 0; i < 256; i++) {
		// from what I see online, I need to iterate over 256 keys.
		// I hope more reading clears up some of the confusion I have over this.
	}
		// Store key states
	// Return released keys
	return 0; // Stub return
}


