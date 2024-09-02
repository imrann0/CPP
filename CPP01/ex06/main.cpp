#include <iostream>
#include "Harl.hpp"

int main (int ar, char **av)
{
	Harl harl;

	if (ar != 2)
		std::cout << "Invalid number of arguments" << std::endl;
	else
		harl.complain(std::string(av[1]));
	return (0);
}
