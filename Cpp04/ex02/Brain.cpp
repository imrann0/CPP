#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor Called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "No Idea";
}

Brain::~Brain()
{
	std::cout << "Destructor Called" << std::endl;
}

Brain::Brain(const Brain &copy) :_ideas()
{
	std::cout << "Copy Constructor Called" << std::endl;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = copy._ideas[i];
}
Brain& Brain::operator=(const Brain &opt)
{
	std::cout << "Brain Copy Assignment Operator Called" << std::endl;
	if (this != &opt)
	{
		for(int i = 0; i < 100; i++)
			_ideas[i] = opt._ideas[i];
	}
	return *this;
}

std::string Brain::getIdeas(size_t i) const
{
	return (this->_ideas[i]);
}

void	Brain::setIdeas(size_t i, std::string ideas)
{
	this->_ideas[i] = ideas;
}
