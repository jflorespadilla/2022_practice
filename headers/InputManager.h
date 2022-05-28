#pragma once
#include <Windows.h>
#include <iostream>

class InputManager{
public:
	InputManager(HANDLE& hStdin, DWORD& fdwSaveOldMode);
	~InputManager();
	char GetKey();

private:
	HANDLE _hStdin;
	DWORD _fdwSaveOldMode;
};