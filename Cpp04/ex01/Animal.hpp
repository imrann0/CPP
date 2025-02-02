#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal& operator=(const Animal &copy);
		virtual void makeSound(void) const;
		virtual std::string getType() const;
};

#endif
