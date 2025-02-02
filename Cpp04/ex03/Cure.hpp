#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure &copy);
		Cure& operator=(const Cure &opt);
		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif
