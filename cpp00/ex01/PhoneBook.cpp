/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 03:10:11 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/09 03:28:56 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	std::cout << "\033c\033[1;37mWelcome to your OWN PhoneBook!\033[0m" << std::endl
	<< "Please input your command: ADD, SEARCH, EXIT\n" << std::endl;
	this->_index = 0;
	this->_count = 0;
	return;
}
PhoneBook::~PhoneBook(){
	return;
}

Contact	PhoneBook::_getContact(int index) const{
	return this->_contacts[index - 1];
}
int		PhoneBook::_getCount() const{
	return this->_count;
}
void	PhoneBook::addContact(){
	Contact		contact;
	std::string	string;

	while (!lineToString("Add First Name: ", string, false))
		continue;
	contact.setFirstName(string);
	while (!lineToString("Add Last Name: ", string, false))
		continue;
	contact.setLastName(string);
	while (!lineToString("Add Nickname: ", string, false))
		continue;
	contact.setNickname(string);
	while (!lineToString("Add Phone Number: ", string, true))
		continue;
	contact.setPhoneNum(string);
	while (!lineToString("Add Darkest Secret: ", string, false))
		continue;
	contact.setSecret(string);
	PhoneBook::_setContact(contact);
}

void	PhoneBook::_printContact(int index){
	std::string string;
	if (index >= 0 && index <= _count){
		string = this->_contacts[index].getFirstName();
		std::cout << string << std::endl;
	}
}


void	PhoneBook::searchContact(){
	std::string	in;
	int			index;
	lineToString("Coucou! Dis moi le contact que tu veux voir! ntgrm ^^", in, false);
	index = converter<int>(in);
	PhoneBook::_printContact(index);
}

void	PhoneBook::_setContact(Contact contact){
	this->_contacts[this->_index] = contact;
	if (this->_count < 8)
		_count++;
	this->_index = (this->_index + 1) % 8;
	return;
}

bool	lineToString(const std::string prompt, std::string &input, const bool isNum){
	std::string	string;

	std::cout << prompt;
	std::getline(std::cin, string);
	if (string.empty()){
		return false;
	}
	for (size_t i = 0; i < string.length(); i++){
		if (!std::isprint(string[i])){
			return false;
		}
		if (isNum && !std::isdigit(string[i])){
			return false;
		}
	}
	input = string;
	return true;
}
