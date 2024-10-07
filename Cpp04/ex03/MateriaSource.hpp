#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& opt);
		~MateriaSource();
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const &type);
	private:
		AMateria* _inventory[4];
		int _inventoryCount;
};

#endif
