#include "iter.h"
#include <string>
#include <iostream>
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

template <typename type> 
void printElements(type const& elem) {std::cout << elem << " ";}
void printTitle(std::string const& title) {
	std::cout << std::endl << YELLOW << title << RESET << std::endl;
}
void mult(int& n) {n *= 2;}
void capitalize(std::string& str) {
	if (!str.empty() && str[0] >= 'a' && str[0] <= 'z') str[0] -= 32;
}


int main() {
	printTitle("-- Int array Test --");

	int arrayInt[] = {1, 2, 3, 4, 5};
	size_t arrayLen = sizeof(arrayInt) / sizeof(arrayInt[0]);
	std::cout << "Before: ";
	iter(arrayInt, arrayLen, printElements<int>); std::cout << std::endl;

	iter(arrayInt, arrayLen, mult);
	std::cout << "After: ";
	iter(arrayInt, arrayLen, printElements<int>); std::cout << std::endl;

	printTitle("-- String array Test --");
	std::string arrayStr[] = {"Hatsune", "miku", "kawaii", ":3"};
	arrayLen = sizeof(arrayStr) / sizeof(arrayStr[0]);
	std::cout << "Before: ";
	iter(arrayStr, arrayLen, printElements<std::string>); std::cout << std::endl;

	iter(arrayStr, arrayLen, capitalize);
	std::cout << "After: ";
	iter(arrayStr, arrayLen, printElements<std::string>); std::cout << std::endl;

	return 0;
}