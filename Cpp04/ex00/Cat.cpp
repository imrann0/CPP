#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" <<  std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat &opt)
{
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	this->_type = opt._type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << this->getType() << " says: Meow meow" << std::endl;
}

std::string Cat::getType() const
{
	return(this->_type);
}
