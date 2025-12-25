#pragma once

#	include <iostream>
#	include <cmath>

class Fixed {
	private:
		int					_rawBits;
		static const int	_bitsFraction = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		Fixed(int const num);
		Fixed(float const num);
		Fixed	&operator=(Fixed const &copy);

		bool	operator>(Fixed const &right) const;
		bool	operator<(Fixed const &right) const;
		bool	operator>=(Fixed const &right) const;
		bool	operator<=(Fixed const &right) const;
		bool	operator==(Fixed const &right) const;
		bool	operator!=(Fixed const &right) const;

		Fixed	operator+(Fixed const &right) const;
		Fixed	operator-(Fixed const &right) const;
		Fixed	operator*(Fixed const &right) const;
		Fixed	operator/(Fixed const &right) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		Fixed static &min(Fixed &a, Fixed &b);
		Fixed const static &min(Fixed const &a, Fixed const &b);

		Fixed static &max(Fixed &a, Fixed &b);
		Fixed const static &max(Fixed const &a, Fixed const &b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream & operator<<(std::ostream &o, Fixed const &i);
