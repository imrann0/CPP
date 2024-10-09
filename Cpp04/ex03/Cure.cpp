#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure Constructor Called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor Called" << std::endl;
}
Cure::Cure(const Cure &copy): AMateria(copy)
{
	std::cout << "Cure Copy Consturcor Called" << std::endl;
}

Cure& Cure::operator=(const Cure &opt)
{
	if (this == &opt)
		return (*this);
	this->_type = opt._type;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
