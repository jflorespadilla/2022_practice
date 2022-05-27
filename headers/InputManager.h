#pragma once
#include <Windows.h>
#include <iostream>

class InputManager{
public:
	InputManager(HANDLE& hStdin, DWORD& fdwSaveOldMode);
	~InputManager();

private:
	HANDLE _hStdin;
	DWORD _fdwSaveOldMode;
};