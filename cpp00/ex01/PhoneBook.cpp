/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 03:10:11 by mkettab           #+#    #+#             */
/*   Updated: 2025/12/15 02:16:54 by mkettab          ###   ########.fr       */
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

void	PhoneBook::_printContact(int index){
	std::string string;

	if (index >= 0 && index < _count){
		std::cout << "For the contact number " << index + 1 << ":" << std::endl;
		string = this->_contacts[index].getFirstName();
		std::cout << "First Name: " << string << std::endl;
		string = this->_contacts[index].getLastName();
		std::cout << "Last Name: " << string << std::endl;
		string = this->_contacts[index].getNickname();
		std::cout << "Nickname: " << string << std::endl;
		string = this->_contacts[index].getPhoneNum();
		std::cout << "Phone Number: " << string << std::endl;
		string = this->_contacts[index].getSecret();
		std::cout << "Secret: " << string + "\n" << std::endl;
	} else {
		std::cout << "Error: Index not in range!\n" << std::endl;
	}
}
Contact	PhoneBook::_getContact(int index) const{
	return this->_contacts[index - 1];
}
int		PhoneBook::_getCount() const{
	return this->_count;
}
void	PhoneBook::_setContact(Contact contact){
	this->_contacts[this->_index] = contact;
	if (this->_count < 8)
		_count++;
	this->_index = (this->_index + 1) % 8;
	return;
}
bool	PhoneBook::_addContactLine(const std::string &prompt, std::string &in){
	int		error;

	error = 0;
	while (error == 0)
		error = lineToString(prompt, in, false);
	if (error == 2)
		return false;
	else
		return true;
}
std::string	PhoneBook::_genWSpace(size_t num){
	std::string ret;

	for (size_t i = 0; i < num; i++)
		ret = ret + " ";
	return ret;
}
std::string PhoneBook::_verifLen(std::string string){
	if (string.length() > 10)
		string = string.substr(0, 9) + ".";
	else
		string = string + PhoneBook::_genWSpace(10 - string.length());
	return string;
}

void	PhoneBook::searchContact(){
	std::string	in;
	int			index;
	int			error;
	Contact		contact;

	if (this->_count == 0){
		std::cout << "There's no contact (yet...)\n" << std::endl;
		return;
	}
	std::cout << "\nList of Contacts: \n" << std::endl;
	std::cout << "Index     |First Name|Last Name |Nickname  |" << std::endl <<
	"--------------------------------------------" << std::endl;
	for (int i = 0; i < this->_count; i++){
		contact = this->_contacts[i];
		in = contact.getFirstName();
		in = PhoneBook::_verifLen(in);
		std::cout << i + 1 << PhoneBook::_genWSpace(9) << "|" << in << "|";
		in = contact.getLastName();
		in = PhoneBook::_verifLen(in);
		std::cout << in << "|";
		in = contact.getNickname();
		in = PhoneBook::_verifLen(in);
		std::cout << in << "|\n" << 
		"--------------------------------------------\n" << std::endl;
	}
	error = 0;
	while (error == 0)
		error = lineToString("[SEARCH] ", in, true);
	if (error == 2)
		return;
	index = converter<int>(in);
	index--;
	PhoneBook::_printContact(index);
}
void	PhoneBook::addContact(){
	Contact		contact;
	std::string	string;

	if (!PhoneBook::_addContactLine("Add First Name: ", string))
		return;
	contact.setFirstName(string);
	if (!PhoneBook::_addContactLine("Add Last Name: ", string))
		return;
	contact.setLastName(string);
	if (!PhoneBook::_addContactLine("Add Nickname: ", string))
		return;
	contact.setNickname(string);
	while (lineToString("Add Phone Number: ", string, true) == 0)
		continue;
	contact.setPhoneNum(string);
	if (!PhoneBook::_addContactLine("Add Darkest Secret: ", string))
		return;
	contact.setSecret(string);
	std::cout << "\nContact Added Successfully!\n" << std::endl;
	PhoneBook::_setContact(contact);
}
