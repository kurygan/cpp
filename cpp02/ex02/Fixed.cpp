#include "Fixed.hpp"

Fixed::Fixed() {
	this->_rawBits = 0;
}
Fixed::~Fixed() {}
Fixed::Fixed(Fixed const &other) {
	*this = other;
}
Fixed::Fixed(int const num){
	this->_rawBits = num << _bitsFraction;
}
Fixed::Fixed(float const num) {
	this->_rawBits = static_cast<int>(roundf(num * (1 << this->_bitsFraction)));
}

Fixed	&Fixed::operator=(Fixed const &copy) {
	if (this != &copy) {
		this->_rawBits = copy.getRawBits();
	}
	return *this;
}
std::ostream & operator<<(std::ostream &o, Fixed const &i){
	o << i.toFloat();
	return o;
}

bool	Fixed::operator>(Fixed const &right) const {return this->getRawBits() > right.getRawBits();}
bool	Fixed::operator<(Fixed const &right) const {return this->getRawBits() < right.getRawBits();}
bool	Fixed::operator>=(Fixed const &right) const {return this->getRawBits() >= right.getRawBits();}
bool	Fixed::operator<=(Fixed const &right) const {return this->getRawBits() <= right.getRawBits();}
bool	Fixed::operator==(Fixed const &right) const {return this->getRawBits() == right.getRawBits();}
bool	Fixed::operator!=(Fixed const &right) const {return this->getRawBits() != right.getRawBits();}

Fixed	Fixed::operator+(Fixed const &right) const {return Fixed(this->toFloat() + right.toFloat());}
Fixed	Fixed::operator-(Fixed const &right) const {return Fixed(this->toFloat() - right.toFloat());}
Fixed	Fixed::operator*(Fixed const &right) const {return Fixed(this->toFloat() * right.toFloat());}
Fixed	Fixed::operator/(Fixed const &right) const {if (right != 0) return Fixed(this->toFloat() / right.toFloat()); else return Fixed();}
Fixed	&Fixed::operator++(void) {this->_rawBits++; return *this;}
Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	this->_rawBits++;
	return temp;
}
Fixed	&Fixed::operator--(void) {this->_rawBits--; return *this;}
Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	this->_rawBits--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {if (a < b) return a; return b;}
Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {if (a < b) return a; return b;}
Fixed &Fixed::max(Fixed &a, Fixed &b) {if (a > b) return a; return b;}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {if (a > b) return a; return b;}


int		Fixed::getRawBits(void) const {
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