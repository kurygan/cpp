#include "Dog.hpp"

Dog::Dog() {
	this->_brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(copy) {*this = copy; std::cout << "Dog copy constructor called" << std::endl;}
Dog::~Dog() {delete this->_brain; std::cout << "Dog destructor called" << std::endl;}

Dog		&Dog::operator=(const Dog &copy) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copy) {
		this->type = copy.getType();
		delete this->_brain;
		this->_brain = new Brain(copy.getBrain());
	}
	return *this;
}

void	Dog::makeSound() const {std::cout << "Bark" << std::endl;}
Brain	Dog::getBrain() const {return *this->_brain;}