#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
	ClapTrap a("ali");
	ScavTrap b("kerem");
	std::cout << std::endl;
	b.attack("ali");
	b.takeDamage(20);
	b.beRepaired(20);
	b.guardGate();
	std::cout << std::endl;
	a.attack("imran");
	a.takeDamage(9);
	a.beRepaired(8);
	std::cout << std::endl;
}
