#include "Base.h"

int main() {
    // 1. Initialisation de la graine aléatoire (ESSENTIEL !)
    // Si tu oublies ça, tu auras la même séquence à chaque exécution.
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "--- Début des tests ex02 ---" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "\nTest n°" << i + 1 << ":" << std::endl;

        // On génère un type aléatoire
        Base *ptr = generate();

        // On teste l'identification par pointeur
        std::cout << "Identification par pointeur : ";
        identify(ptr);

        // On teste l'identification par référence
        std::cout << "Identification par référence : ";
        identify(*ptr); // On déréférence le pointeur pour envoyer la ref

        // On libère la mémoire pour éviter les leaks (on est à 42, rappelle-toi !)
        delete ptr;
    }

    std::cout << "\n--- Test d'un pointeur NULL ---" << std::endl;
    identify(static_cast<Base*>(NULL));

    return 0;
}