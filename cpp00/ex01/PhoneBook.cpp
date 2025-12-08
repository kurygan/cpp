#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	return;
}
PhoneBook::~PhoneBook(){
	return;
}

Contact	PhoneBook::getContact(int index){
	return this->_contacts[index - 1];
}
int		PhoneBook::getCount(){
	return this->_count;
}

void	PhoneBook::setContact(Contact contact){
	this->_contacts[this->_index] = contact;
	if (this->_count < 8)
		_count++;
	this->_index = (this->_index + 1) % 8;
	return;
}