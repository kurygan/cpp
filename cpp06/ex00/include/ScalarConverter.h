#pragma once

#	include <iostream>
#	include <string>
#	include <climits>
#	include <iomanip>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& copy);
		~ScalarConverter();
		ScalarConverter& operator=(ScalarConverter const& copy);
	public:
		static void convert(std::string param);
};