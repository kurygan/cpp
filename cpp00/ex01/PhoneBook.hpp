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

		Contact	getContact(int index) const;
		int		getCount() const;
		void	addContact();
		void	searchContact();

	private:
		Contact	_contacts[8];
		int		_count;
		int		_index;
		void	_setContact(Contact contact);
};

bool	lineToString(const std::string prompt, std::string &input, const bool isNum);

#endif