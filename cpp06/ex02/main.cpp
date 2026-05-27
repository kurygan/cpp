#include "Base.h"

int main() {
	std::srand(std::time(0));

	for (int i = 0; i < 5; i++) {
		std::cout << "\nTest " << i + 1 << ":" << std::endl;

		Base *ptr = generate();
		std::cout << "Pointer Identification: "; identify(ptr);
		std::cout << "Reference Identification: "; identify(*ptr);
		delete ptr;
	}

	std::cout << "NULL Pointer Test:" << std::endl;
	identify(static_cast<Base*>(NULL));

	return 0;
}