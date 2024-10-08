#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default Constructor Called" << std::endl;
	_type = "(null)";
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria Name Constructor Called" << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria& copy)
{
	std::cout << "AMateria Copy Constructor Called" << std::endl;
	*this = copy;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor Called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &opt)
{
	if (this == &opt)
		return (*this);
	this->_type = opt._type;
	return (*this);
}

const std::string& AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	if (this->getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else
		std::cout << "* heals " << target.getName() << " *" << std::endl;
}

