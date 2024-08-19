#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name )
{
	Zombie *hud = new Zombie[N];
	for(int i = 0; i < N; i++)
		hud[i].SetName(name);
	return (hud);
}
