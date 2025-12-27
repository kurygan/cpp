/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 02:26:36 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/27 03:44:06 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\033[34mFragTrap constructor Called!\033[0m" << std::endl;
}
FragTrap::~FragTrap() {
	std::cout << "\033[34mFragTrap destructor Called!\033[0m" << std::endl;
}
FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {*this = copy;}
FragTrap	&FragTrap::operator=(FragTrap const &copy) {
	if (this != &copy){
		ClapTrap::operator=(copy);
	}
	return *this;
}

void	FragTrap::attack(std::string const &target) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "FragTrap [" << this->_name << "] attacks [" << target << "], causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << this->_name << " is Dead!" << std::endl;
	else
		std::cout << this->_name << " is Exhausted!" << std::endl;
}
void	FragTrap::highFivesGuys() {
	std::cout << "[" << this->_name << "] wants a High Five!" << std::endl;
}