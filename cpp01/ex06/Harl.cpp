/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 00:37:01 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/14 22:26:07 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}
Harl::~Harl(){
}

void	Harl::debug(){
	std::cout << "<debug> I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void	Harl::info(){
	std::cout << "<info> I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(){
	std::cout << "<warning> I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void	Harl::error(){
	std::cout << "<error> This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level){
	bool	found = false;
	void	(Harl::*func[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	std::string	cases[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++) {
		if (cases[i] == level)
			found = true;
		if (found == true)
			(this->*func[i])();
	}
	if (found == false)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}