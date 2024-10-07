#include "MateriaSource.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	std::cout << "learnMaterai Called" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	std::cout << "createMateria Callled" << std::endl;
	AMateria* newMateria;

	newMateria = new Ice();
	return newMateria;
}
