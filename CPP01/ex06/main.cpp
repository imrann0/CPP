#include <iostream>
#include "Harl.hpp"

int main (int ar, char **av)
{
	Harl harl;
	std::string str;

	str = av[1];
	if (ar != 2)
		std::cout << "Invalid number of arguments" << std::endl;
	else
		harl.complain(str);
	return (0);
}
