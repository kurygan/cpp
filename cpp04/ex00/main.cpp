#include "Cat.hpp"
#include "Dog.hpp"

int main(){
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	j->makeSound();      // Doit afficher un aboiement, pas un son d'animal générique !

	delete meta;
	delete j;
	delete i;
}