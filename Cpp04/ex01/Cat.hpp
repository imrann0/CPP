#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &copy);
		Cat& operator=(const Cat &copy);
		void makeSound(void) const;
		std::string getType() const;
		void	setBrainIdea(size_t i, std::string idea);
		void	printIdeas();
	private:
		Brain *_brain;
};

#endif
