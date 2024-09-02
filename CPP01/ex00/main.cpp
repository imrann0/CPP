#include "Zombie.hpp"


Zombie	*newZombie(std::string name);
void	randomChump( std::string name );

int main(void)
{
	Zombie a("FOO");
	a.announce();

	Zombie *z = newZombie("LOO");
	z->announce();
	delete z;
	randomChump("RAA");

	return (0);
}
