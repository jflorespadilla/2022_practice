#pragma once
#include <iostream>
#include <string>

// Switching back to using iostream going to work on windows input in other projects.

class InputManager{
public:
	InputManager();
	~InputManager();
	char GetKey();
	std::string GetLine();

private:

};