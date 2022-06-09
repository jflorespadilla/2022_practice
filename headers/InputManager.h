#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

class InputManager{
public:
	InputManager(HANDLE* hStdin);
	~InputManager();
	char GetKey();
	std::string GetLine();

private:
	HANDLE* _hStdin;
};