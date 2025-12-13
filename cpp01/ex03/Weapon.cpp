/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:04:00 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/13 23:05:11 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type){
	this->_type = type;
	return;
}
Weapon::~Weapon(){
	return;
}
const std::string	&Weapon::getType() const{
	return this->_type;
}
void				Weapon::setType(const std::string &type){
	this->_type = type;
}