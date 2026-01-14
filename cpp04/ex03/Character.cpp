#include "Character.hpp"

Character::Character(): _name("missing name") {
	for (size_t i = 0; i < 4; i++) this->_inv[i] = NULL;
}
Character::Character(std::string const &name): _name(name) {
	for (size_t i = 0; i < 4; i++) this->_inv[i] = NULL;
}
Character::Character(Character const &copy) {
	for (size_t i = 0; i < 4; i++) this->_inv[i] = NULL;
	*this = copy;
}
Character	&Character::operator=(Character const &copy) {
	if (this != &copy) {
		this->_name = copy.getName();
		for (size_t i = 0; i < 4; i++)
			if (this->_inv[i] != NULL) {
				delete this->_inv[i];
				this->_inv[i] = NULL;
			}
		for (size_t i = 0; i < 4; i++){
			if (copy._inv[i] == NULL)
				this->_inv[i] = NULL;
			else
				this->_inv[i] = copy._inv[i]->clone();
		}
	}
	return *this;
}
Character::~Character() {
	for (size_t i = 0; i < 4; i++)
		if (this->_inv[i] != NULL)
			delete this->_inv[i];
}

std::string const	&Character::getName() const {return this->_name;}
void				Character::equip(AMateria* m) {
	if (!m) return;
	for(size_t i = 0; i < 4; i++)
		if (this->_inv[i] == NULL) {
			this->_inv[i] = m;
			return;
		}
	std::cout << "Inventory Full!" << std::endl;
}
void				Character::unequip(int i) {
	if (i >= 0 && i < 4)
		this->_inv[i] = NULL;
}
void				Character::use(int i, ICharacter &target) {
	if (i >= 0 && i < 4 && this->_inv[i] != NULL)
		this->_inv[i]->use(target);
}
