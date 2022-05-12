#include "../headers/InputManager.h"

InputManager::InputManager(HANDLE& hStdin)
	:
	fdwSaveOldMode(0),
	inputKey('\0')
{
	_hStdin = hStdin;
}

InputManager::~InputManager() {

}

VOID InputManager::ErrorExit(const char* lpszMessage) {
	std::cerr << "Error: " << lpszMessage << std::endl;
	SetConsoleMode(_hStdin, fdwSaveOldMode);
	ExitProcess(0);
}

VOID InputManager::KeyEventProc(KEY_EVENT_RECORD ker) {
	if (ker.bKeyDown) {
		inputKey = ker.uChar.AsciiChar;
	}
	else {
		inputKey = '\0';
	}
}

char InputManager::GetKey()
{
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter = 0;

	if (_hStdin == INVALID_HANDLE_VALUE) {
		ErrorExit("GetStdHandle");
	}
	if (!GetConsoleMode(_hStdin, &fdwSaveOldMode)) {
		ErrorExit("GetConsoleMode");
	}

	fdwMode = ENABLE_LINE_INPUT;
	if (!SetConsoleMode(_hStdin, fdwMode)) {
		ErrorExit("SetConsoleMode");
	}

	// Reding the handle for the next 100 input events
	while (counter++ <= 100) {
		if (!ReadConsoleInput(
			_hStdin,
			irInBuf,
			128,
			&cNumRead)) {
			ErrorExit("ReadConsoleInput");
		}

		for (i = 0; i < cNumRead; i++) {
			switch (irInBuf[i].EventType) {
			case KEY_EVENT:
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MENU_EVENT:
				break;

			default:
				ErrorExit("Unknown event type");
			}
		}
	}

	SetConsoleMode(_hStdin, fdwSaveOldMode);
	return inputKey;
}
