#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat Default Constructor Called" << std::endl;
	_type = "Default";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called" <<  std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat Copy Constructor Called" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat &opt)
{
	std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
	this->_type = opt._type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << this->getType() << " says: Meow meow" << std::endl;
}

std::string WrongCat::getType() const
{
	return(this->_type);
}
