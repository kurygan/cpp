#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define YELLOW "\033[1;33m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define BLUE   "\033[34m"
#define RESET  "\033[0m"

void printTitle(std::string const &title) {
	std::cout << std::endl << YELLOW << "-- " + title + " --" << RESET << std::endl;
}

int main() {
	Bureaucrat boss("Le Boss", 1);
	Bureaucrat intern("Intern", 150);
	Bureaucrat mid("Mid", 40);

	AForm* shrub = new ShrubberyCreationForm("Garden");
	AForm* robot = new RobotomyRequestForm("Bender");
	AForm* pardon = new PresidentialPardonForm("Obama");

	printTitle("Test 1: Intern signing");
	try {
		intern.signForm(*shrub);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	printTitle("Test 2: Shrubbery Creation");
	try {
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	printTitle("Test 3: Robotomy Request");
	try {
		boss.signForm(*robot);
		mid.executeForm(*robot);
		boss.executeForm(*robot);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	printTitle("Test 4: Presidential Pardon (Should Fail!)");
	try {
		boss.signForm(*pardon);
		mid.executeForm(*pardon);
	} catch (std::exception &e) {
		std::cout << "Bureaucrat " << mid.getName() << " failed because " << e.what() << std::endl;
	}

	printTitle("TEST 5 : Presidential Pardon (Shouldn't Fail!)");
	try {
		boss.executeForm(*pardon);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	delete shrub;
	delete robot;
	delete pardon;

	return 0;
}