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
Fixed::Fixed(int const num){
	std::cout << "Int Constructor Called!" << std::endl;
	this->_rawBits = num << _bitsFraction;
}
Fixed::Fixed(float const num) {
	std::cout << "Float Constructor Called!" << std::endl;
	this->_rawBits = static_cast<int>(roundf(num * (1 << this->_bitsFraction)));
}

Fixed	&Fixed::operator=(Fixed const &copy) {
	std::cout << "Copy Operator Called!" << std::endl;
	if (this != &copy) {
		this->_rawBits = copy.getRawBits();
	}
	return *this;
}
std::ostream & operator<<(std::ostream &o, Fixed const &i){
	o << i.toFloat();
	return o;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits Called!" << std::endl;
	return this->_rawBits;
}
void	Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}
int		Fixed::toInt(void) const {
	return (this->_rawBits >> this->_bitsFraction);
}
float	Fixed::toFloat(void) const {
	return (static_cast<float>(this->_rawBits) / (1 << this->_bitsFraction));
}