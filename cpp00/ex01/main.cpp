/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 03:10:17 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/09 03:13:41 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(){
	PhoneBook phoneBook;
	std::string	choice;

	do {
		if (lineToString("[$] ", choice, false)){
			if (choice == "ADD")
				phoneBook.addContact();
		}
	} while (choice != "EXIT");
	return 0;
}