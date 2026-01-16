#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(copy) {*this = copy; std::cout << "Cat copy constructor called" << std::endl;}
Cat::~Cat() {delete this->_brain; std::cout << "Cat destructor called" << std::endl;}

Cat		&Cat::operator=(const Cat &copy) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy) {
		this->type = copy.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(copy.getBrain());
	}
	return *this;
}

void	Cat::makeSound() const {std::cout << "Meow Meow!" << std::endl;}
Brain	Cat::getBrain() const {return *this->_brain;}