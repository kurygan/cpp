#include <iostream>
#include "Bureaucrat.hpp"

void    testHeader(std::string title) {
    std::cout << std::endl << "\033[1;32m---------------------------------------" << std::endl;
    std::cout << "TEST: " << title << std::endl;
    std::cout << "---------------------------------------\033[0m" << std::endl;
}

int main() {

	testHeader("CONSTRUCTION NORMALE");
	try {
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;

		Bureaucrat bill("Bill", 150);
		std::cout << bill << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	testHeader("ERREUR: GRADE TROP HAUT (0)");
	try {
		Bureaucrat god("God", 0);
		std::cout << "Ce message ne devrait pas s'afficher !" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}

	testHeader("ERREUR: GRADE TROP BAS (151)");
	try {
		Bureaucrat stagiaire("Stagiaire", 151);
		std::cout << "Ce message ne devrait pas s'afficher !" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}

	testHeader("INCREMENTATION LIMITE (1 -> 0)");
	try {
		Bureaucrat boss("Big Boss", 2);
		std::cout << "Avant : " << boss << std::endl;

		boss.incrementGrade();
		std::cout << "Après 1 incrément : " << boss << std::endl;

		boss.incrementGrade();
		std::cout << "Après 2 incréments : " << boss << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}

    testHeader("DECREMENTATION LIMITE (149 -> 151)");
    try {
		Bureaucrat dave("Dave", 149);
		std::cout << "Avant : " << dave << std::endl;

		dave.decrementGrade();
		std::cout << "Après 1 décrément : " << dave << std::endl;

		dave.decrementGrade();
		std::cout << "Après 2 décréments : " << dave << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}

	return 0;
}