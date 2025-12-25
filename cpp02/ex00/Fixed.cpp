#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Constructor Called!" << std::endl;
	this->_rawBits = 0;
}
Fixed::~Fixed() {std::cout << "Destructor Called!" << std::endl;}
Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy Constructor Called!" << std::endl;
	*this = other;
}
Fixed	&Fixed::operator=(Fixed const &copy) {
	std::cout << "Copy Operator Called!" << std::endl;
	if (this != &copy) {
		this->_rawBits = copy.getRawBits();
	}
	return *this;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits Called!" << std::endl;
	return this->_rawBits;
}
void	Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}