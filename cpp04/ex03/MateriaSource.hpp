#pragma once

#	include "IMateriaSource.hpp"
#	include "AMateria.hpp"

class MateriaSource: public IMateriaSource {
	private:
		AMateria *_materia[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		MateriaSource&	operator=(MateriaSource const &copy);
		~MateriaSource();

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);
};