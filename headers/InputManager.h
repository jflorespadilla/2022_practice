#pragma once
#include <Windows.h>
#include <iostream>

class InputManager{
public:
	InputManager(HANDLE& hStdin, DWORD& fdwSaveOldMode);
	~InputManager();
	VOID ErrorExit(const char* lpszMessage);
	VOID KeyEventProc(KEY_EVENT_RECORD ker);
	char GetKey();

private:
	HANDLE _hStdin;
	DWORD _fdwSaveOldMode;
	char inputKey;
};