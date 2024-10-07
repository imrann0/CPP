#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: IMateriaSource
{
	public:
		~MateriaSource();
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const &type);
};

#endif
