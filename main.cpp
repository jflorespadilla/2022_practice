#include <iostream>
#include <vector>
#include "headers/vectorFunctions.h"
#include "headers/hero.h"

int main() {
	greetings();

	// Working with vectors
	std::cout << "First we'll be working with some vecotrs!\n";

	std::vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	displayFirstElementOfVector(v1);
	displayVectorContents(v1);
	appendToVector(v1, 12);

	// Testing out my custom class
	std::cout << "Now to test out my custom class!!" << std::endl << std::endl;

	hero myhero;

	std::cout << myhero.getName() << std::endl << std::endl;

	system("PAUSE");

	return 0;
}