#include "AMateria.hpp"

AMateria::AMateria() {}
AMateria::AMateria(std::string const &id) : type(id) {}
AMateria::AMateria(AMateria const &copy) {*this = copy;}
AMateria::~AMateria() {}
AMateria			&AMateria::operator=(AMateria const &copy) {(void)copy; return *this;}
void				AMateria::use(ICharacter &target) {(void)target;}
std::string const	&AMateria::getType() const {return this->type;}
