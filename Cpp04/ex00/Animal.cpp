#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default Constructor Called" << std::endl;
	_type = "Default";
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" <<  std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor Called" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal &opt)
{
	std::cout << "Animal Copy Assignment Operator Called" << std::endl;
	if (this == &opt)
		return (*this);
	this->_type = opt._type;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "This Animal doesn't make any sound" << std::endl;
}

std::string Animal::getType() const
{
	return(this->_type);
}
