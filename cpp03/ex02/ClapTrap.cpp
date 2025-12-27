/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:03:35 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/27 02:47:56 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "\033[34mConstructor Called!\033[0m" << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << "\033[34mDestructor Called!\033[0m" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const &copy) {
	std::cout << "\033[34mCopy Constructor Called!\033[0m" << std::endl;
	*this = copy;
}
ClapTrap	&ClapTrap::operator=(ClapTrap const &copy) {
	if (this != &copy){
		this->_name = copy.getName();
		this->_hitPoints = copy.getHP();
		this->_energyPoints = copy.getEP();
		this->_attackDamage = copy.getAD();
	}
	return *this;
}

void	ClapTrap::attack(std::string const &target) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else if (this->_hitPoints == 0)
		std::cout << this->_name << " is Dead!" << std::endl;
	else
		std::cout << this->_name << " is Exhausted!" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount) {
	int i = this->_hitPoints - amount;
	if (i < 0){
		std::cout << this->_name << " took " << this->_hitPoints << " damage!" << std::endl;
		this->_hitPoints = 0;
	}
	else {
		std::cout << this->_name << " took " << amount << " damage!" << std::endl;
		this->_hitPoints -= amount;
	}
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints > 0 && this->_energyPoints > 0) {
		std::cout << this->_name << " regenerated " << amount << " HP!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else if (this->_energyPoints == 0)
		std::cout << "Not enough Energy!" << std::endl;
}

std::string	ClapTrap::getName(void) const {return this->_name;}
int			ClapTrap::getHP(void) const {return this->_hitPoints;}
int			ClapTrap::getEP(void) const {return this->_energyPoints;}
int			ClapTrap::getAD(void) const {return this->_attackDamage;}