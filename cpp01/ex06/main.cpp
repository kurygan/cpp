/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 00:36:53 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/14 22:26:28 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av){
	Harl harl;

	if (ac != 2){
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	
	std::string string(av[1]);
	harl.complain(string);
	return 0;
}