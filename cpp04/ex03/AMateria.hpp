#pragma once

#	include <iostream>
#	include <string>

class ICharacter;

class AMateria {
	protected:
		std::string type;

	public:
		AMateria();
		AMateria(std::string const &id);
		AMateria(AMateria const &copy);
		virtual ~AMateria();
		AMateria	&operator=(AMateria const &copy);

		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};