#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// Couleurs pour la lisibilité
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void    printTitle(std::string title) {
    std::cout << std::endl << BLUE << "=== " << title << " ===" << RESET << std::endl;
}

int main()
{
    // --- TEST 1 : Création de Formulaires (Valides et Invalides) ---
    printTitle("TEST 1: FORM CONSTRUCITON");
    
    try {
        std::cout << "Tentative de création d'un formulaire valide (Standard 50/100)..." << std::endl;
        Form taxes("Impots", 50, 100);
        std::cout << GREEN << taxes << RESET << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "Erreur inattendue : " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << "Tentative de création avec grade trop haut (0)..." << std::endl;
        Form godMode("GodMode", 0, 50);
    } catch (std::exception &e) {
        std::cerr << GREEN << "Exception attrapée (attendue) : " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << "Tentative de création avec grade trop bas (151)..." << std::endl;
        Form trash("Poubelle", 151, 50);
    } catch (std::exception &e) {
        std::cerr << GREEN << "Exception attrapée (attendue) : " << e.what() << RESET << std::endl;
    }

    // --- TEST 2 : Signature réussie ---
    printTitle("TEST 2: SIGNATURE REUSSIE");
    try {
        Bureaucrat  boss("Big Boss", 1);
        Form        contract("Contrat CDI", 10, 50); // Grade 10 requis pour signer

        std::cout << boss << std::endl;
        std::cout << contract << std::endl;

        // Le boss signe le contrat
        boss.signForm(contract);

        std::cout << GREEN << "Après signature : " << contract << RESET << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "Erreur : " << e.what() << RESET << std::endl;
    }

    // --- TEST 3 : Echec de signature (Grade insuffisant) ---
    printTitle("TEST 3: SIGNATURE ECHOUEE (GRADE TROP BAS)");
    try {
        Bureaucrat  stagiaire("Stagiaire", 150);     // Grade 150
        Form        nuclear("Codes Nucléaires", 1, 1); // Grade 1 requis

        std::cout << stagiaire << std::endl;
        std::cout << nuclear << std::endl;

        // Le stagiaire essaie de signer (doit échouer proprement via signForm)
        stagiaire.signForm(nuclear); 

        // On vérifie que le formulaire n'est PAS signé
        std::cout << YELLOW << "Etat final du formulaire : " << nuclear << RESET << std::endl;
    } catch (std::exception &e) {
        std::cerr << RED << "Erreur critique : " << e.what() << RESET << std::endl;
    }

    // --- TEST 4 : Double Signature (Optionnel mais intéressant) ---
    printTitle("TEST 4: SIGNER UN FORMULAIRE DEJA SIGNE");
    try {
        Bureaucrat  manager("Manager", 40);
        Form        paper("Note de frais", 50, 100);

        manager.signForm(paper); // 1ère fois : OK
        manager.signForm(paper); // 2ème fois : Dépend de ton implémentation (souvent OK ou message info)
    } catch (std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}