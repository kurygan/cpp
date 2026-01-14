#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure") {}
Cure::Cure(Cure const &copy): AMateria(copy) {}
Cure::~Cure() {}
Cure			&Cure::operator=(Cure const &copy) {
	if (this != &copy) AMateria::operator=(copy);
	return *this;
}

AMateria*	Cure::clone() const {return new Cure(*this);}
void		Cure::use(ICharacter &target) {std::cout << "* shoots an Cure ball at " << target.getName() << " *" << std::endl;}