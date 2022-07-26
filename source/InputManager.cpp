#include "../headers/InputManager.h"

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

char InputManager::GetKey() {
	char retChar;
	std::cin >> retChar;

	return retChar;
}

std::string InputManager::GetLine() {
	std::string retString;
	std::getline(std::cin, retString, '\n');

	return std::string();
}




