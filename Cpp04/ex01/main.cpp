#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	{
		size_t size = 10;
		Animal *s[size];
		for (size_t i = 0; i < size; i++)
		{
			if (i % 2)
			{
				s[i] = new Dog();
			}
			else
				s[i] = new Cat();
		}

		for(size_t i = 0; i < size; i++)
			s[i]->makeSound();

		for(size_t i = 0; i < size; i++)
			delete s[i];
	}
	{
		Cat a;
		Dog b;

		a.setBrainIdea(0, "Sunlight and a Cozy Bed");
		a.setBrainIdea(1, "Waiting for Mealtime");
		a.setBrainIdea(2, "Play and Hunting Instincts");
		a.setBrainIdea(3, "Exploration and Curiosity");
		a.setBrainIdea(4, "Bonding with the Owner");

		b.setBrainIdea(0, "Chasing the Ball");
		b.setBrainIdea(1, "Loyal Protection");
		b.setBrainIdea(2, "Excited Walk Time");
		b.setBrainIdea(3, "Begging for Treats");
		b.setBrainIdea(4, "Comforting the Owner");

		a.printIdeas();
		b.printIdeas();
	}

}
