#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog Default Constructor Called" << std::endl;
	_brain = new Brain();
	_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" <<  std::endl;
	delete _brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	_brain = new Brain(*copy._brain);
	*this = copy;
}

Dog& Dog::operator=(const Dog &opt)
{
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	if (this == &opt)
		return (*this);
	for (size_t i = 0; i < 100; i++)
		_brain[i] = opt._brain[i];
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

void Dog::setBrainIdea(size_t i, std::string idea)
{
	this->_brain->setIdeas(i, idea);
}

void Dog::printIdeas()
{
	if (_brain->getIdeas(0) == "No Idea")
		std::cout << _brain->getIdeas(0) << std::endl;
	else
		for(size_t i = 0; _brain->getIdeas(i) != "No Idea"; i++)
			std::cout <<  _brain->getIdeas(i) << std::endl;
}
