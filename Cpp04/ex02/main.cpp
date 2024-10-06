#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
	Dog l;
	l.setBrainIdea(0, "asfasf");
	Dog s(l);
	s.printIdeas();
}
