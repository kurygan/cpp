#pragma once

#	include <iostream>
#	include <string>
#	include <limits>
#	include <iomanip>
#	include <cfloat>
#	include <cstdlib>

template <typename T>
void printConverter(T value){
	std::cout << "char: ";
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "non-displayable" << std::endl;
	else std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

	std::cout << "int: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else std::cout << static_cast<int>(value) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& copy);
		~ScalarConverter();
		ScalarConverter& operator=(ScalarConverter const& copy);
	public:
		static void convert(std::string param);
};