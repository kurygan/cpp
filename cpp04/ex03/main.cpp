#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

// Fonction utilitaire pour imprimer des titres en couleur (si ton terminal le supporte)
void printTitle(std::string title) {
    std::cout << "\n\033[1;33m>>> " << title << " <<<\033[0m" << std::endl;
}

int main() {
	printTitle("TEST 1: SUBJECT MANDATORY TEST");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	printTitle("TEST 2: DEEP COPY CHARACTER");
	{
		Character* original = new Character("Original");
		AMateria* m1 = new Ice();
		original->equip(m1);
		std::cout << "[+] Creating Copy from Original..." << std::endl;
		Character* copy = new Character(*original); // Constructeur de copie
		std::cout << "[+] Deleting Original..." << std::endl;
		delete original;
		std::cout << "[+] Testing Copy (Should still work)..." << std::endl;
		Character* target = new Character("Target");
		copy->use(0, *target); // Doit afficher "shoots an ice bolt..."
		delete target;
		delete copy;
	}
	printTitle("TEST 3: INVENTORY MANAGEMENT");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* hero = new Character("Hero");
		AMateria* tmp;
		std::cout << "[+] Filling inventory..." << std::endl;
		tmp = src->createMateria("ice"); hero->equip(tmp); // Slot 0
		tmp = src->createMateria("ice"); hero->equip(tmp); // Slot 1
		tmp = src->createMateria("cure"); hero->equip(tmp); // Slot 2
		tmp = src->createMateria("cure"); hero->equip(tmp); // Slot 3
		std::cout << "[+] Trying to overfill (Slot 4)..." << std::endl;
		tmp = src->createMateria("ice"); 
		hero->equip(tmp); // L'inventaire est plein
		delete tmp; 
		std::cout << "[+] Using invalid slots..." << std::endl;
		hero->use(-1, *hero);
		hero->use(4, *hero);
		hero->use(10, *hero);
		delete hero;
		delete src;
	}
	printTitle("TEST 4: UNEQUIP MEMORY LEAK CHECK");
	{
		ICharacter* player = new Character("Player");
		AMateria* m = new Ice();
		player->equip(m);
		std::cout << "[+] Unequipping slot 0..." << std::endl;
		player->unequip(0);
		std::cout << "[+] Manually deleting unequipped materia..." << std::endl;
		delete m;
		delete player;
	}
	return 0;
}