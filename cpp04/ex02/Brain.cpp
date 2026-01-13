#include "Brain.hpp"

Brain::Brain() {std::cout << "Brain Default Constructor called" << std::endl;}
Brain::Brain(const Brain& copy) {std::cout << "Brain Copy Constructor called" << std::endl; *this = copy;}
Brain::~Brain() {std::cout << "Brain Destructor called" << std::endl;}
Brain& Brain::operator=(const Brain& copy) {
	std::cout << "Brain Assignment operator called" << std::endl;
	if (this != &copy) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = copy.ideas[i];
		}
	}
	return *this;
}
