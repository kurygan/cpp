#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {std::cout << "WrongAnimal default constructor called" << std::endl;}
WrongAnimal::WrongAnimal(WrongAnimal const &copy) {std::cout << "WrongAnimal copy constructor called" << std::endl; *this = copy;}
WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal destructor called" << std::endl;}

WrongAnimal WrongAnimal::operator=(WrongAnimal const &copy) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &copy) {
		this->type = copy.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const {std::cout << "Woof or Meow, idc its generic" << std::endl;}

std::string WrongAnimal::getType() const {return this->type;}