/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 02:26:36 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/27 02:38:02 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "\033[34mScavTrap constructor Called!\033[0m" << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << "\033[34mScavTrap destructor Called!\033[0m" << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {*this = copy;}
ScavTrap	&ScavTrap::operator=(ScavTrap const &copy) {
	if (this != &copy){
		ClapTrap::operator=(copy);
	}
	return *this;
}

void	ScavTrap::attack(std::string const &target) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ScavTrap \"" << this->_name << "\" attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << this->_name << " is Dead!" << std::endl;
	else
		std::cout << this->_name << " is Exhausted!" << std::endl;
}
void	ScavTrap::guardGate() {
	std::cout << "[" << this->_name << "] went Gate Keeper mode!" << std::endl;
}