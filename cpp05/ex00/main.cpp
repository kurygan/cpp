#include <iostream>
#include "Bureaucrat.hpp"

#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

void printTitle(std::string const &title) {
	std::cout << std::endl << YELLOW << title << RESET << std::endl;
}

int main() {

	printTitle("-- Default Construction --");
	try {
		Bureaucrat donovan("Donovan", 1);
		std::cout << donovan << std::endl;

		Bureaucrat benoit("Benoit", 150);
		std::cout << benoit << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	printTitle("-- Error Test: Grade too High --");
	try {
		Bureaucrat nan("Does not exist", 0);
		std::cout << "Non displayable (normally)" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	printTitle("-- Error Test: Grade too Low --");
	try {
		Bureaucrat nan("Non-Existent", 151);
		std::cout << "Non displayable (normally)" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	printTitle("-- Error Test: Increment limits --");
	try {
		Bureaucrat boss("Boss", 2);
		std::cout << "Stage 1: " << boss << std::endl;

		boss.incrementGrade();
		std::cout << "Stage 2: " << boss << std::endl;

		boss.incrementGrade();
		std::cout << "Stage 3: " << boss << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	printTitle("-- Error Test: Decrement limits --");
	try {
		Bureaucrat janitor("Janitor", 149);
		std::cout << "Stage 1: " << janitor << std::endl;

		janitor.decrementGrade();
		std::cout << "Stage 2: " << janitor << std::endl;

		janitor.decrementGrade();
		std::cout << "Stage 3: " << janitor << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}