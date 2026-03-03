#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Array.h>
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

void printTitle(std::string const& title) {
	std::cout << std::endl << YELLOW << title << RESET << std::endl;
}

int main() {
	std::srand(std::time(NULL));
	printTitle("-- Default constructor (no arguments) --");

	Array<int> empty;
	std::cout << "Array Size: " << empty.size() << std::endl;
	try {
		std::cout << "Trying to get access to it..." << std::endl;
		std::cout << empty[0] << std::endl;
	} catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	printTitle("-- Default constructor (arguments) --");

	Array<int> intArray(10);
	for(size_t i = 0; i < intArray.size(); i++) {
		intArray[i] = (std::rand() % 100) + 1;
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
	}
	std::cout << "Array Size: " << intArray.size() << std::endl;

	printTitle("-- Out of bounds exception --");
	try {
		std::cout << "Over the size..." << std::endl;
		std::cout << intArray[10];
	} catch (std::exception const& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		std::cout << "Negative index" << std::endl;
		std::cout << intArray[-1] << std::endl; 
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	printTitle("-- Test with other type (strings) --");
	Array<std::string> strArray(2);
	strArray[0] = "Hello";
	strArray[1] = "World!";

	for (size_t i = 0; i < strArray.size(); i++)
		std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
	return 0;
}