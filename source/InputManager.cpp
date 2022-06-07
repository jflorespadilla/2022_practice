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
	// It seems to be working, but I need to do more testing.
	for (DWORD i = 0; i < recordsRead; i++) {
		if (irInBuf[i].Event.KeyEvent.bKeyDown) {
			return irInBuf[i].Event.KeyEvent.uChar.AsciiChar;
		}
	}
}


