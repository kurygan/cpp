/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:14:42 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/10 02:32:01 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHord(int n, std::string name){
	Zombie* hord = new Zombie[n];
	
	for (int i = 0; i < n; i++)
		hord[i].setName(name);
	return hord;
}