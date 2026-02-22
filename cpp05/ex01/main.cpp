#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define YELLOW "\033[1;33m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define BLUE   "\033[34m"
#define RESET  "\033[0m"

void printTitle(std::string const &title) {
	std::cout << std::endl << YELLOW << "-- " + title + " --" << RESET << std::endl;
}

int main()
{
	try {
		printTitle("Valid Form Construction");
		Form taxes("Taxes", 50, 100);
		std::cout << GREEN << "[OK]\n" << taxes << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	try {
		printTitle("Error Test: Creating too High Form");
		Form impossible("Impossible", 0, 50);
	} catch (std::exception &e) {
		std::cerr << GREEN << "[OK] Error: " << e.what() << RESET << std::endl;
	}

	try {
		printTitle("Error Test: Creating too Low Form");
		Form trash("Trash", 151, 50);
	} catch (std::exception &e) {
		std::cerr << GREEN << "[OK] Error: " << e.what() << RESET << std::endl;
	}

	printTitle("Valid Signing");
	try {
		Bureaucrat boss("Boss", 1);
		Form contract("Contract", 10, 50);

		std::cout << boss << std::endl;
		std::cout << contract << std::endl;

		boss.signForm(contract);

		std::cout << GREEN << "[OK]\n" << contract << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Erreur: " << e.what() << RESET << std::endl;
	}

	printTitle("Error Test: Bureaucrat's Grade too Low to Sign");
	try {
		Bureaucrat intern("Intern", 150);
		Form nuclearCodes("Nuclear Codes", 1, 1);

		std::cout << intern << std::endl;
		std::cout << nuclearCodes << std::endl;

		intern.signForm(nuclearCodes); 

		if (!nuclearCodes.ifSigned())
			std::cout << GREEN << "[OK]\n" << nuclearCodes << RESET << std::endl;
		else
			std::cout << RED << "[KO]\n" << nuclearCodes << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	printTitle("Error Test: Already Signed Form");
	try {
		Bureaucrat manager("Manager", 40);
		Form contract("Contract", 50, 100);

		manager.signForm(contract);
		manager.signForm(contract);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}