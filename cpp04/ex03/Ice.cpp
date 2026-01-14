#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice") {}
Ice::Ice(Ice const &copy): AMateria(copy) {}
Ice::~Ice() {}
Ice			&Ice::operator=(Ice const &copy) {
	if (this != &copy) AMateria::operator=(copy);
	return *this;
}

AMateria*	Ice::clone() const {return new Ice(*this);}
void		Ice::use(ICharacter &target) {std::cout << "* shoots an ice ball at " << target.getName() << " *" << std::endl;}