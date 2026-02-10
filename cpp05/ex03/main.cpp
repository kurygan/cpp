#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp" 

void testIntern(Intern& intern, const std::string& formName, const std::string& target) {
    std::cout << "\n-----------------------------------------------------" << std::endl;
    std::cout << "TEST: Demande de création de '" << formName << "' sur '" << target << "'" << std::endl;
    
    AForm* form = NULL;
    
    try {
        form = intern.makeForm(formName, target);

        if (form) {
            std::cout << "✅ SUCCÈS : Le formulaire " << *form << " a été créé !" << std::endl;
            Bureaucrat boss("The Boss", 1);
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        } else {
            std::cout << "❌ ÉCHEC : Le pointeur retourné est NULL." << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "❌ EXCEPTION : " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== DÉBUT DES TESTS DU STAGIAIRE (INTERN) ===" << std::endl;

    Intern someRandomIntern;

    testIntern(someRandomIntern, "robotomy request", "Bender");
    testIntern(someRandomIntern, "shrubbery creation", "Jardin");
    testIntern(someRandomIntern, "presidential pardon", "Hannibal Lecter");

    testIntern(someRandomIntern, "demande d'augmentation", "Moi");

    std::cout << "\n=== FIN DES TESTS ===" << std::endl;
    return 0;
}