#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // 1. Initialisation du générateur de nombres aléatoires pour la Robotomie

    std::cout << "--- Initialisation des Bureaucrates ---" << std::endl;
    Bureaucrat boss("Le Boss", 1);
    Bureaucrat stagiaire("Stagiaire", 150);
    Bureaucrat mid("Cadre Moyen", 40);

    std::cout << "\n--- Création des Formulaires (Polymorphisme) ---" << std::endl;
    // On utilise des pointeurs sur la classe de base pour tester le polymorphisme
    AForm* shrub = new ShrubberyCreationForm("jardin");
    AForm* robot = new RobotomyRequestForm("Bender");
    AForm* pardon = new PresidentialPardonForm("Arnaud Montebourg");

    std::cout << "\n--- TEST 1 : Le Stagiaire essaie de tout signer ---" << std::endl;
    try {
        stagiaire.signForm(*shrub);
    } catch (std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2 : Signature et Exécution du Shrubbery ---" << std::endl;
    try {
        boss.signForm(*shrub);
        boss.executeForm(*shrub); // Devrait créer le fichier jardin_shrubbery
    } catch (std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
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