#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &copy);
		Dog& operator=(const Dog &copy);
		void makeSound(void) const;
		std::string getType() const;
		void	setBrainIdea(size_t i, std::string idea);
		void	printIdeas();
	private:
		Brain *_brain;
};

#endif
