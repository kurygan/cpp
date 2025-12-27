/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 03:43:46 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/27 03:47:51 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\033[1;32m--- TEST 1: Naissance d'un FragTrap ---\033[0m" << std::endl;
        FragTrap frag("Grendizer");
        frag.attack("Vega"); 
        std::cout << "\n> Tentative de socialisation :" << std::endl;
        frag.highFivesGuys();
    std::cout << "\n------------------------------------------\n" << std::endl;
    std::cout << "\033[1;32m--- TEST 2: Résistance et Mort (Edge Cases) ---\033[0m" << std::endl;
        FragTrap tank("Tanky");
        tank.takeDamage(110); 
        std::cout << "> Action post-mortem (ne doit rien faire) :" << std::endl;
        tank.highFivesGuys(); 
        tank.attack("Ghost");
        tank.beRepaired(50);
    std::cout << "\n------------------------------------------\n" << std::endl;
    std::cout << "\033[1;32m--- TEST 3: La Forme Canonique (Copie profonde) ---\033[0m" << std::endl;
        FragTrap original("Original");
        original.takeDamage(20); // HP = 80
        std::cout << "\n> Création de la copie (Copy Constructor)..." << std::endl;
        FragTrap copie(original);
        std::cout << "> Modification de l'original..." << std::endl;
        original.takeDamage(70); // Original HP = 10
        std::cout << "> Test de survie de la copie :" << std::endl;
        copie.highFivesGuys(); // Doit marcher
        std::cout << "Si la copie a survécu et l'original est quasi-mort, c'est gagné." << std::endl;
    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "\033[1;31mFinal Destruction:\033[0m" << std::endl;
    return 0;
}