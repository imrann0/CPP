#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog Default Constructor Called" << std::endl;
	_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" <<  std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog &opt)
{
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	this->_type = opt._type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << this->getType() << " says: Woof woof" << std::endl;
}

std::string Dog::getType() const
{
	return(this->_type);
}
