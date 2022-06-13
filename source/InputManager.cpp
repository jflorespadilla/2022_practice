#include "../headers/InputManager.h"

InputManager::InputManager(HANDLE* hStdin) {
	_hStdin = hStdin;
}

InputManager::~InputManager() {

}

char InputManager::GetKey() {
	INPUT_RECORD irInBuf[265];
	DWORD recordsRead;
	ReadConsoleInput(*_hStdin, irInBuf, 256, &recordsRead);

	for (DWORD i = 0; i < recordsRead; i++) {
		if (irInBuf[i].Event.KeyEvent.bKeyDown) {
			return irInBuf[i].Event.KeyEvent.uChar.AsciiChar;
		}
	}
}

std::string InputManager::GetLine() {
	INPUT_RECORD irInBuf[265];
	DWORD fdwSaveOldMode, fdwMode;
	DWORD recordsRead;
	GetConsoleMode(_hStdin, &fdwSaveOldMode);
	fdwMode = ENABLE_LINE_INPUT;
	SetConsoleMode(_hStdin, fdwMode);

	ReadConsoleInput(*_hStdin, irInBuf, 256, &recordsRead);
	
	for (DWORD i = 0; i < recordsRead; i++) {
		if (!irInBuf[i].Event.KeyEvent.bKeyDown) {
			// Possibly use asynckeys here to load up string?
		}
	}

	SetConsoleMode(_hStdin, fdwSaveOldMode);
	return std::string();
}




