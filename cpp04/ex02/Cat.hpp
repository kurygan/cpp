#pragma once

#	include "Animal.hpp"
#	include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain	*_brain;
	public:
		Cat();
		~Cat();
		Cat(Cat const &copy);
		Cat		&operator=(Cat const &copy);

		void	makeSound() const;
		Brain	getBrain() const;
};