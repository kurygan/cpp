#include "PhoneBook.hpp"

int		lineToString(const std::string prompt, std::string &input, const bool isNum){
	std::string	string;

	std::cout << prompt;
	std::getline(std::cin, string);
	if (std::cin.eof()) {
		std::cin.clear();
		std::cin.ignore(string.size());
		return 2;
	}
	if (string.empty() || std::cin.eof()){
		return 0;
	}
	for (size_t i = 0; i < string.length(); i++){
		if (!std::isprint(string[i])){
			return 0;
		}
		if (isNum && !std::isdigit(string[i])){
			return 0;
		}
	}
	input = string;
	return 1;
}