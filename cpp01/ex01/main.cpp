/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:26:34 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/10 02:31:13 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	Zombie* horde = zombieHord(5, "Gerard");
	
	for (size_t i = 0; i < 5; i++){
		std::cout << "id " << i << ":" << std::endl;
		horde[i].announce();
	}
	delete[] horde;
}