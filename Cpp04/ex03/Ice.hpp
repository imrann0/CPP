#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
class Ice: AMateria
{
	AMateria* clone() const;
	void use(ICharacter& target);
};


#endif
