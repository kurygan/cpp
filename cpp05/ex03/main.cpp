#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp" 

#define YELLOW "\033[1;33m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define BLUE   "\033[34m"
#define RESET  "\033[0m"

void printTitle(std::string const &title) {
	std::cout << std::endl << YELLOW << "-- " + title + " --" << RESET << std::endl;
}

void testIntern(Intern& intern, const std::string& formName, const std::string& target) {
	std::cout << "\n-----------------------------------------------------" << std::endl;
	std::cout << "Creation of '" << formName << "' on '" << target << "'" << std::endl;

	AForm* form = NULL;

	try {
		form = intern.makeForm(formName, target);

		std::cout << "The Form:\n " << *form << std::endl;
		Bureaucrat boss("The Boss", 1);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

int main() {
	printTitle("Intern Testing");

	Intern someRandomIntern;

	testIntern(someRandomIntern, "robotomy request", "Bender");
	testIntern(someRandomIntern, "shrubbery creation", "Jardin");
	testIntern(someRandomIntern, "presidential pardon", "Hannibal Lecter");

	testIntern(someRandomIntern, "demande d'augmentation", "Moi");
	return 0;
}