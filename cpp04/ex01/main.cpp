#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "--- 1. BASIC POLYMORPHISM TEST ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " says: ";
	j->makeSound();
	std::cout << i->getType() << " says: ";
	i->makeSound();

	delete j;
	delete i;

	std::cout << "\n--- 2. ARRAY OF ANIMALS TEST ---" << std::endl;
	const int count = 4;
	Animal* animals[count];

	for (int k = 0; k < count / 2; k++)
		animals[k] = new Dog();
	for (int k = count / 2; k < count; k++)
		animals[k] = new Cat();

	std::cout << "\nCleaning up the array..." << std::endl;
	for (int k = 0; k < count; k++)
		delete animals[k];

	std::cout << "\n--- 3. DEEP COPY TEST ---" << std::endl;
	Dog basic;
	{
		std::cout << "\nCreating a copy in a scope..." << std::endl;
		Dog tmp = basic;
		std::cout << "Exiting scope, tmp will be destroyed" << std::endl;
	} 
	std::cout << "Basic is still alive and well." << std::endl;

	return 0;
}