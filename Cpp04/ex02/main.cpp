#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
	Dog l;
	l.setBrainIdea(0, "sleep");
	Dog s(l);
	s.printIdeas();
}
