/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:56:00 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/13 23:10:47 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name): _weapon(NULL), _name(name){
	return ;
}
HumanB::~HumanB(){
	return;
}
void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}
void	HumanB::attack(){
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their bare hands" << std::endl;
}