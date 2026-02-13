#include "ScalarConverter.h"

int main(int ac, const char *av[]) {
	if (ac != 2) {
		std::cerr << "Error, Use: ./converter [num or char]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}