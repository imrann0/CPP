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
	this->_type = opt._type;
	return (*this);
}


