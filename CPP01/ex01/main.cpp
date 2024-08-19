#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name );

int main(void)
{
	Zombie *Hud = zombieHorde(5, "Ali");
	for(int i = 0; i < 5; i++)
		Hud[i].announce();
	delete [] Hud;
	return (0);
}
