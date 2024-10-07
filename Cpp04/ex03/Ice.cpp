#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice Constructor Called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor Called" << std::endl;
}
Ice::Ice(const Ice &copy): AMateria(copy)
{
	std::cout << "Ice Copy Consturcor Called" << std::endl;
}

Ice& Ice::operator=(const Ice &opt)
{
	if (this == &opt)
		return (*this);
	this->_type = opt._type;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
