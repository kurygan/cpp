#include "Dog.hpp"

Dog::Dog() {this->type = "Dog"; std::cout << "Dog default constructor called" << std::endl;}
Dog::Dog(const Dog &copy) : Animal(copy) {*this = copy; std::cout << "Dog copy constructor called" << std::endl;}
Dog::~Dog() {std::cout << "Dog destructor called" << std::endl;}

Dog Dog::operator=(const Dog &copy) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &copy) {
        Animal::operator=(copy);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Bark" << std::endl;
}