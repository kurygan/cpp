#pragma once

#	include <iostream>

class Fixed {
	private:
		int					_rawBits;
		static const int	_bitsFraction = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		Fixed	&operator=(Fixed const &copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};