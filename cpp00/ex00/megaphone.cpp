/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:43:36 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/04 22:55:23 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cctype>

int	main(int ac, char **av){
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		++av;
		while (*av){
			std::string str(*av);
			for (size_t i = 0; i < str.length(); i++)
				std::cout << (char)std::toupper(str[i]);
			av++;
		}
		std::cout << std::endl;
	}
	return 0;
}