/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:37:16 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/27 02:43:48 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\033[1;32m--- TEST 1: Instanciation et cycle basique ---\033[0m" << std::endl;
        ClapTrap robot("CL4P-TP");
        robot.attack("Bandit");
        robot.takeDamage(5);
        robot.beRepaired(3);
        robot.takeDamage(1);
    std::cout << std::endl;
    std::cout << "\033[1;32m--- TEST 2: La Mort (0 HP) ---\033[0m" << std::endl;
        ClapTrap deadBot("Kenny");
        deadBot.takeDamage(20);
        deadBot.attack("Someone");
        deadBot.beRepaired(10);
    std::cout << std::endl;
    std::cout << "\033[1;32m--- TEST 3: Panne d'énergie (Loop d'attaque) ---\033[0m" << std::endl;
        ClapTrap spammer("SpammerBot");
        for (int i = 0; i < 12; i++) {
            std::cout << "Round " << i + 1 << ": ";
            spammer.attack("Target");
        }
    std::cout << std::endl;
    std::cout << "\033[1;32m--- TEST 4: Forme Canonique (Copie & Assignation) ---\033[0m" << std::endl;
        ClapTrap original("Original");
        original.takeDamage(5);
        std::cout << "> Test Copy Constructor:" << std::endl;
        ClapTrap copy(original); 
        std::cout << "> Test Assignment Operator:" << std::endl;
        ClapTrap assigned("Basic");
        assigned = original;
    return 0;
}