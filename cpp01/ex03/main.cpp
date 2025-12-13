/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:26:00 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/13 23:09:17 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main()
{
    // ---------------------------------------------------------
    // TEST 1 : HumanA
    // Il prend une référence à l'arme dans son constructeur.
    // ---------------------------------------------------------
    {
        std::cout << "--- TEST 1 : HumanA (Bob) ---" << std::endl;
        
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        
        bob.attack(); // Devrait afficher : Bob attacks with their crude spiked club
        
        std::cout << "[Modification de l'arme via setType]" << std::endl;
        club.setType("some other type");
        
        bob.attack(); // Devrait afficher : Bob attacks with their some other type
    }
    // Ici, 'bob' et 'club' sont détruits automatiquement.

    std::cout << std::endl; // Séparation visuelle

    // ---------------------------------------------------------
    // TEST 2 : HumanB
    // Il n'a pas d'arme au début, on lui en donne une après.
    // ---------------------------------------------------------
    {
        std::cout << "--- TEST 2 : HumanB (Jim) ---" << std::endl;

        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");

        // Cas : Pas encore d'arme
        std::cout << "[Attaque sans arme]" << std::endl;
        jim.attack(); // Devrait afficher : Jim attacks with their bare hands

        // Cas : On équipe l'arme
        std::cout << "[Equipement de l'arme]" << std::endl;
        jim.setWeapon(club);
        jim.attack(); // Devrait afficher : Jim attacks with their crude spiked club

        // Cas : Modification de l'arme externe
        std::cout << "[Modification de l'arme via setType]" << std::endl;
        club.setType("some other type");
        jim.attack(); // Devrait afficher : Jim attacks with their some other type
    }
    // Ici, 'jim' et 'club' sont détruits automatiquement.

    return 0;
}