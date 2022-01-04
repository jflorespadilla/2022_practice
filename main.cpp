#include <iostream>
#include <vector>

void greetings();

int main() {
	greetings();

	std::cout << "First we'll be working with some vecotrs!\n";

	std::vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	std::cout << "This should display the first element of 1.\n\n";
	std::cout << "Output: " << v1[0] << std::endl;

	std::cout << "\nThis should loop and output the contents of the vector." << std::endl << std::endl;

	for (auto& v : v1) {
		std::cout << v << std::endl;
	}

	std::cout << "\n\nNow I will add an element to the end of  the vector and display the output." << std::endl;

	std::cout << "Appending..." << std::endl << std::endl;
	v1.push_back(10);

	std::cout << v1.back() << std::endl << std::endl;

	system("PAUSE");
	
	return 0;
}

void greetings() {
	std::cout << "Hello and welcome to 2022! This is where I'll go from zero to programming hero!" << std::endl << std::endl;
	std::cout << "My goal is to program everyday this year. While it doesn't have to be this project, I do want this to serve as my go-to program to messaround in." << std::endl <<std::endl;
	std::cout << "Simply hope is to get my career back on track and make my way into some sort of development role somewhere." << std::endl << std::endl;
}