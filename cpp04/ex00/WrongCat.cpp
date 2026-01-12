#include "WrongCat.hpp"

WrongCat::WrongCat() {this->type = "WrongCat"; std::cout << "WrongCat default constructor called" << std::endl;}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {*this = copy; std::cout << "WrongCat copy constructor called" << std::endl;}
WrongCat::~WrongCat() {std::cout << "WrongCat destructor called" << std::endl;}

WrongCat WrongCat::operator=(const WrongCat &copy) {
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &copy) {
        WrongAnimal::operator=(copy);
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}