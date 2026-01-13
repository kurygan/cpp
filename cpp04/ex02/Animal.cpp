#include "Animal.hpp"

Animal::Animal() : type("Animal") {std::cout << "Animal default constructor called" << std::endl;}
Animal::Animal(Animal const &copy) {std::cout << "Animal copy constructor called" << std::endl; *this = copy;}
Animal::~Animal() {std::cout << "Animal destructor called" << std::endl;}

Animal &Animal::operator=(Animal const &copy) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return *this;
}

void Animal::makeSound() const {std::cout << "Woof or Meow, idc its generic" << std::endl;}

std::string Animal::getType() const {return this->type;}