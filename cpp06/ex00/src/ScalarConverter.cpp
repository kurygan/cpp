#include "ScalarConverter.h"

void charConvert(int c) {
	std::cout << "char: " << char(c) << std::endl;
	std::cout << "int: " << c << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
}
//void intConvert(int num) {
//	std::cout << "char: " << std::endl;
//	std::cout << "int: " << std::endl;
//	std::cout << "double: " << std::endl;
//	std::cout << "float: " << std::endl;
//}
//void doubleConvert(double num) {
//	std::cout << "char: " << std::endl;
//	std::cout << "int: " << std::endl;
//	std::cout << "double: " << std::endl;
//	std::cout << "float: " << std::endl;
//}
//void floatConvert(float num) {
//	std::cout << "char: " << std::endl;
//	std::cout << "int: " << std::endl;
//	std::cout << "double: " << std::endl;
//	std::cout << "float: " << std::endl;
//}
void maxConvert() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << __INT_MAX__ << std::endl;
	std::cout << "double: " << __DBL_MAX__<< std::endl;
	std::cout << "float: " << __FLT_MAX__ << "f" << std::endl;
}
void minConvert() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
	std::cout << "float: " << __FLT_MIN__ << "f" << std::endl;
}
void nanConvert() {
	std::cout << "char: non-displayable" << std::endl;
	std::cout << "int: 0" << std::endl;
	std::cout << "double: 0.0" << std::endl;
	std::cout << "float: 0.0f" << std::endl;
}

void checkChar(std::string param) {
	if (param.length() == 1) charConvert(param[0]);
	else if (param == "+inf" || param == "+inff") maxConvert();
	else if (param == "-inf" || param == "-inff") minConvert();
	else if (param == "nan" || param == "nanf") nanConvert();
}

void ScalarConverter::convert(std::string param) {
	if (!std::isprint(param[0])) {std::cerr << "Error, Use: ./converter [num or char]"; return;}
	if (std::isprint(param[0]) && !std::isdigit(param[0])) checkChar(param);
}