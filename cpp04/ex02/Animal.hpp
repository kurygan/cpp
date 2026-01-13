#pragma once

#	include <iostream>
#	include <string>

class Animal {
	protected:
		std::string		type;
	public:
		Animal();
		Animal(Animal const &copy);
		virtual ~Animal();
		Animal			&operator=(Animal const &copy);

		virtual void	makeSound() const = 0;
		std::string		getType() const;
};