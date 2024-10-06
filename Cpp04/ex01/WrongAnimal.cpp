#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
	_type = "Default";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called" <<  std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &opt)
{
	std::cout << "WrongAnimal Copy Assignment Operator Called" << std::endl;
	this->_type = opt._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "This WrongAnimal doesn't make any sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(this->_type);
}
