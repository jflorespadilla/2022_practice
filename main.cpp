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
	
	std::cout << "Declare a second hero with starting values" << std::endl << std::endl;

	hero myhero2("Bob", "Morph", 10, 12, 6);
	std::cout << myhero2.getName() << std::endl << std::endl;

	std::cout << "Testing the use of a copy constructor" << std::endl << std::endl;

	hero myhero3 = myhero2;
	std::cout << myhero3.getName() << std::endl << std::endl;

	std::cout << "Now I will attempt to make a vector of heroes" << std::endl << std::endl;

	std::vector<hero> myheroVector{myhero, myhero2, myhero3};

	for (auto v : myheroVector) {
		std::cout << "Hero Name: " << v.getName() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Names will be updated..." << std::endl << std::endl;

	int count = 1;
	char countChar;

	for (int i = 0; i < myheroVector.size(); i++) {
		std::cout << "Updating... ";

		std::string heroName = "Hero ";
		countChar = char(count + 96);
		heroName.push_back(countChar);
		myheroVector[i].setName(heroName);
		std::cout << myheroVector[i].getName() << std::endl;

		count++;
	}

	for (auto v : myheroVector) {
		std::cout << "Hero Name: " << v.getName() << std::endl;
	}
	std::cout << std::endl << std::endl;

	system("PAUSE");

	return 0;
}