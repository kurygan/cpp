/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 03:10:17 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/09 21:25:39 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(){
	PhoneBook phoneBook;
	std::string	choice;
	int			error;

	do {
		error = lineToString("[MENU] ", choice, false);
		if (error == 1){
			if (choice == "ADD")
				phoneBook.addContact();
			if (choice == "SEARCH")
				phoneBook.searchContact();
		} else if (error == 2){
			break;
		}
	} while (choice != "EXIT");
	return 0;
}