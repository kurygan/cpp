#ifndef PHONEBOOK_H
#	define PHONEBOOK_H

#	include "Contact.hpp"
#	include <iostream>
#	include <sstream>

template <typename TYPE>
TYPE converter(const std::string &string){
	std::stringstream	sstream;
	TYPE				type;

	sstream.str(string);
	sstream >> type;
	return type;
}

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact();

	private:
		Contact	_contacts[8];
		int		_count;
		int		_index;
		void	_setContact(Contact contact);
		void	_printContact(int index);
		Contact	_getContact(int index) const;
		int		_getCount() const;
};

bool	lineToString(const std::string prompt, std::string &input, const bool isNum);

#endif