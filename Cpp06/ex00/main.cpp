#include "ScalarConverter.hpp"
#include <iostream>
int main(int ar, char **av)
{
	if (ar == 2)
	{
		std::string value(av[1]);
		std::string status = ScalarConverter::control(value);
		ScalarConverter::print(status);
	}
}
