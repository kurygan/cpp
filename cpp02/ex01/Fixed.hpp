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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream & operator<<(std::ostream &o, Fixed const &i);