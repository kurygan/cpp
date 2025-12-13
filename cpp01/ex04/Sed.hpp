#ifndef SED_H
#	define SED_H

#	include <iostream>
#	include <string>
#	include <fstream>
#	include <sstream>

class Sed {
	private:
		std::string	_in;
		std::string	_out;
	public:
		Sed(const std::string &in);
		~Sed();
		void	replace(const std::string &search, const std::string &replace);
};

#endif