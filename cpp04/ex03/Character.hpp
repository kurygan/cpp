#pragma once

#	include "ICharacter.hpp"
#	include "AMateria.hpp"

class Character: public ICharacter {
	private:
		std::string	_name;
		AMateria*	_inv[4];
	public:
		Character();
		Character(std::string const &name);
		Character(Character const &copy);
		Character &operator=(Character const &copy);
		~Character();

		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int i);
		void				use(int i, ICharacter& target);
};