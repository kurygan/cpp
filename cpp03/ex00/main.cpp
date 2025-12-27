/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:37:16 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/27 01:03:07 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\033[1;32m--- TEST 1: Instanciation et cycle basique ---\033[0m" << std::endl;
    {
        ClapTrap robot("CL4P-TP");

        robot.attack("Bandit"); // Devrait marcher
        robot.takeDamage(5);    // PV: 10 -> 5
        robot.beRepaired(3);    // PV: 5 -> 8, Energy -1
        robot.takeDamage(1);    // PV: 8 -> 7
    }
    std::cout << std::endl;

    std::cout << "\033[1;32m--- TEST 2: La Mort (0 HP) ---\033[0m" << std::endl;
    {
        ClapTrap deadBot("Kenny");

        deadBot.takeDamage(20); // Doit gérer le fait de ne pas avoir HP < 0
        deadBot.attack("Someone"); // Ne doit PAS marcher (mort)
        deadBot.beRepaired(10);    // Ne doit PAS marcher (mort)
    }
    std::cout << std::endl;

    std::cout << "\033[1;32m--- TEST 3: Panne d'énergie (Loop d'attaque) ---\033[0m" << std::endl;
    {
        ClapTrap spammer("SpammerBot");
        
        // On a 10 points d'énergie au départ. On boucle 12 fois.
        // Les 10 premières doivent passer, les 2 dernières doivent échouer.
        for (int i = 0; i < 12; i++) {
            std::cout << "Round " << i + 1 << ": ";
            spammer.attack("Target");
        }
    }
    std::cout << std::endl;

    std::cout << "\033[1;32m--- TEST 4: Forme Canonique (Copie & Assignation) ---\033[0m" << std::endl;
    {
        ClapTrap original("Original");
        original.takeDamage(5); // PV à 5

        // Constructeur de copie
        std::cout << "> Test Copy Constructor:" << std::endl;
        ClapTrap copy(original); 
        // La copie doit avoir le même nom et les mêmes stats (5 PV)
        
        // Opérateur d'affectation
        std::cout << "> Test Assignment Operator:" << std::endl;
        ClapTrap assigned("Basic");
        assigned = original;
        // assigned doit maintenant être une copie de original
    }
    
    return 0;
}