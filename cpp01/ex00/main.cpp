/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 01:52:19 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/10 01:55:56 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	Zombie* zombie = newZombie("Exemple");
	zombie->announce();

	randomChump("Exemple 2");
	delete zombie;
	return 0;
}