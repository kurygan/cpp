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

	printTitle("Test 2: Shrubbery Sign and Execute");
	try {
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3 : Robotomie (50% de chance) ---" << std::endl;
	try {
		boss.signForm(*robot);
		mid.executeForm(*robot); // Le cadre moyen (grade 40) peut executer la robotomie (grade 45)
		boss.executeForm(*robot);
	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4 : Pardon Présidentiel (Trop dur pour le mid) ---" << std::endl;
	try {
		boss.signForm(*pardon);
		mid.executeForm(*pardon); // Devrait échouer (besoin du grade 5)
	} catch (std::exception &e) {
		std::cout << "Normal: " << mid.getName() << " a échoué car : " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 5 : Pardon Présidentiel (Le Boss s'en occupe) ---" << std::endl;
	try {
		boss.executeForm(*pardon);
	} catch (std::exception &e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

	std::cout << "\n--- Nettoyage de la mémoire ---" << std::endl;
	delete shrub;
	delete robot;
	delete pardon;

	return 0;
}