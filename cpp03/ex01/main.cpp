#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\033[1;32m### TEST 1: Construction & Héritage ###\033[0m" << std::endl;
        ScavTrap robot("Serena");
        std::cout << "\n--- Stats & Actions ---" << std::endl;
        robot.attack("Handsome Jack");
        robot.takeDamage(10);
        robot.beRepaired(10);
        std::cout << "\n--- Mode Gardien ---" << std::endl;
        robot.guardGate();
        std::cout << "\n--- Destruction ---" << std::endl;
    std::cout << std::endl << "\033[1;32m### TEST 2: Copie & Capacité (Le test Canonique) ###\033[0m" << std::endl;
        ScavTrap a("Original");
        a.takeDamage(50);
        ScavTrap b(a);
        std::cout << "B HP: " << b.getHP() << " (HP should be 50)" << std::endl;
        b.guardGate();
    return 0;
}