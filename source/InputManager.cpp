#include "../headers/InputManager.h"

InputManager::InputManager(HANDLE& hStdin, DWORD& fdwSaveOldMode) {
	_hStdin = hStdin;
	_fdwSaveOldMode = fdwSaveOldMode;
}

InputManager::~InputManager() {

}

char InputManager::GetKey() {

	for (int i = 0; i < 256; i++) {

	}

	return 0;
}


