#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat Default Constructor Called" << std::endl;
	_brain = new Brain();
	_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" <<  std::endl;
	delete _brain;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	_brain = new Brain(*copy._brain);
	std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(const Cat &opt)
{
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this == &opt)
		return (*this);
	for (size_t i = 0; i < 100; i++)
		_brain[i] = opt._brain[i];
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

void Cat::setBrainIdea(size_t i, std::string idea)
{
	this->_brain->setIdeas(i, idea);
}

void Cat::printIdeas()
{
	if (_brain->getIdeas(0) == "No Idea")
		std::cout << _brain->getIdeas(0) << std::endl;
	else
		for(size_t i = 0; _brain->getIdeas(i) != "No Idea"; i++)
			std::cout <<  _brain->getIdeas(i) << std::endl;
}
