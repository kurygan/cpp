#pragma once

#	include <iostream>
#	include <string>

class WrongAnimal {
	protected:
		std::string		type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &copy);
		virtual ~WrongAnimal();
		WrongAnimal			operator=(WrongAnimal const &copy);

		void	makeSound() const;
		std::string		getType() const;
};