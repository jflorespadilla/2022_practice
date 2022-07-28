#pragma once
#include <iostream>
#include <string>

class InputManager{
public:
	InputManager();
	~InputManager();
	char GetKey();
	int GetInt();
	std::string GetLine();

private:

};