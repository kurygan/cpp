#ifndef PHONEBOOK_H
#	define PHONEBOOK_H

#	include "Contact.hpp"
#	include <iostream>

class PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();

		Contact	getContact(int index);
		int		getCount();

		void	setContact(Contact contact);

	private:
		Contact	_contacts[8];
		int		_count;
		int		_index;
};

#endif