#include "Cat.hpp"

Cat::Cat() {this->type = "Cat"; std::cout << "Cat default constructor called" << std::endl;}
Cat::Cat(const Cat &copy) : Animal(copy) {*this = copy; std::cout << "Cat copy constructor called" << std::endl;}
Cat::~Cat() {std::cout << "Cat destructor called" << std::endl;}

Cat Cat::operator=(const Cat &copy) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &copy) {
        Animal::operator=(copy);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}