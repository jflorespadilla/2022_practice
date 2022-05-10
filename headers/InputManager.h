#pragma once
#include <Windows.h>
#include <iostream>

class InputManager{
public:
	InputManager();
	~InputManager();
	VOID ErrorExit(const char* lpszMessage);
	VOID KeyEventProc(KEY_EVENT_RECORD ker);
	char GetKey();

private:
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	char inputKey;
};