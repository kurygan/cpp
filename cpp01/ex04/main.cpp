/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:28:34 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/14 00:15:13 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av){
	if (ac != 4)
		std::cerr << "Error: Please use it like this: \"./Sed [filename] [s1] [s2]\"" << std::endl;

	Sed sed = Sed(av[1]);
	sed.replace(av[2], av[3]);
	return 0;
}