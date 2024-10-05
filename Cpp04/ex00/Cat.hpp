#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
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
};

#endif
