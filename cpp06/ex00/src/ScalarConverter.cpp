#include "ScalarConverter.h"

bool isInt(std::string param){
	for (int i = 0; i < param.length(); i++)
		if (!std::isdigit(param[i]))
			return false;
	return true;
}
bool isChar(std::string param){
	if (std::isprint(param[0]) && !std::isdigit(param[0]) && param.length() == 1)
		return true;
	return false;
}
bool isDouble(std::string param){
	size_t dotPos = param.find('.');
	if (dotPos != -1 && param.find('.', dotPos + 1) == -1) {
		for (size_t i = 0; i < param.length(); i++) {
			if (!std::isdigit(param[i]) && param[i] != '.')
				return false;
		}
		return true;
	}
	return false;
}
bool isFloat(std::string param){
	size_t dotPos = param.find('.');
	if (dotPos != -1 && param.find('.', dotPos + 1) == -1) {
		size_t i = 0;
		while (i < param.length() - 1) {
			if (!std::isdigit(param[i]) && param[i] != '.')
				return false;
			i++;
		}
		if (param[i] == 'f')
			return true;
	}
	return false;
}

bool minConvert() {
	std::cout << "char: non-displayable" << std::endl;
	std::cout << "int: " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "double: " << std::fixed << std::numeric_limits<double>::min() << std::endl;
	std::cout << "float: " << std::fixed << std::numeric_limits<float>::min() << "f" << std::endl;
	return true;
}
bool maxConvert() {
	std::cout << "char: non-displayable" << std::endl;
	std::cout << "int: " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "double: " << std::fixed << std::numeric_limits<double>::max() << std::endl;
	std::cout << "float: " << std::fixed << std::numeric_limits<float>::max() << "f" << std::endl;
	return true;
}
bool nanConvert() {
	std::cout << "char: non-displayable" << std::endl;
	std::cout << "int: 0" << std::endl;
	std::cout << "double: 0.0" << std::endl;
	std::cout << "float: 0.0f" << std::endl;
	return true;
}

bool isSpecial(std::string param){
	if (param == "-inf" || param == "-inff") return minConvert();
	else if (param == "+inf" || param == "+inff") return maxConvert();
	else if (param == "nan" || param == "nanf") return nanConvert();
	return false;
}

void ScalarConverter::convert(std::string param) {
	if (isChar(param)) printConverter(static_cast<char>(param[0]));
	else if (isInt(param)) printConverter(static_cast<int>(atoi(param.c_str()));
	else if ()
}