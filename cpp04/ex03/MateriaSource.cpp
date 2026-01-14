#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < 4; i++) this->_materia[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource const &copy) {
	for (size_t i = 0; i < 4; i++) this->_materia[i] = NULL;
	*this = copy;
}
MateriaSource&	MateriaSource::operator=(MateriaSource const &copy) {
	if (this != &copy) {
		for (size_t i = 0; i < 4; i++)
			if (this->_materia[i] != NULL) {
				delete this->_materia[i];
				this->_materia[i] = NULL;
			}
		for (size_t i = 0; i < 4; i++) 
			if (copy._materia[i] != NULL)
				this->_materia[i] = copy._materia[i]->clone();
	}
	return *this;
}
MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4; i++)
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
}

void		MateriaSource::learnMateria(AMateria* m) {
	for (size_t i = 0; i < 4; i++)
		if (this->_materia[i] == NULL){
			this->_materia[i] = m;
			return;
		}
	std::cout << "Source is full!" << std::endl;
	delete m;
}
AMateria*	MateriaSource::createMateria(std::string const &type) {
	for (size_t i = 0; i < 4; i++) {
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return NULL;
}