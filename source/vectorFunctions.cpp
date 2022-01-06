#include "../headers/vectorFunctions.h"

void greetings() {
	std::cout << "Hello and welcome to 2022! This is where I'll go from zero to programming hero!" << std::endl << std::endl;
	std::cout << "My goal is to program everyday this year. While it doesn't have to be this project, I do want this to serve as my go-to program to messaround in." << std::endl << std::endl;
	std::cout << "Simply hope is to get my career back on track and make my way into some sort of development role somewhere." << std::endl << std::endl;
}

void displayFirstElementOfVector(std::vector<int>& myVector) {
	std::cout << "This should display the first element of 1.\n\n";
	std::cout << "Output: " << myVector[0] << std::endl << std::endl;
}

void displayVectorContents(std::vector<int>& myVector) {
	std::cout << "This should loop and output the contents of the vector." << std::endl << std::endl;

	for (auto& v : myVector) {
		std::cout << v << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void appendToVector(std::vector<int>& myVector, int newElement) {
	std::cout << "Now I will add an element to the end of  the vector and display the output." << std::endl;
	std::cout << "Appending..." << std::endl << std::endl;
	myVector.push_back(newElement);
	std::cout << myVector.back() << std::endl << std::endl;
}