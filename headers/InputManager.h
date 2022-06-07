#pragma once
#include <Windows.h>
#include <iostream>

class InputManager{
public:
	InputManager(HANDLE* hStdin);
	~InputManager();
	char GetKey();

private:
	HANDLE* _hStdin;
};