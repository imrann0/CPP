#include "ScalarConverter.hpp"
#include <iostream>

int ScalarConverter::_int = 0;
char ScalarConverter::_char = 0;
float ScalarConverter::_float = 0.f;
double ScalarConverter::_double = 0;

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default Constructor Called" << std::endl;
}

void ScalarConverter::convert(std::string value)
{
	(void)value;
	return ;
}

std::string ScalarConverter::control(std::string value)
{
	if (value.compare("nanf") == 0 || value.compare("nan") == 0)
		return (value);
	else if (value.compare("+inf") == 0 || value.compare("+inff"))
		return (value);
	else if (value.compare("-inf") == 0 || value.compare("-inff"))
		return (value);
	return ("NULL");
}

void	ScalarConverter::print(std::string value)
{
	if (value == "+inf" || value == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	else if (value == "-inff" || value == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	else if (value == "nanf" || value == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -nanf" << std::endl;
		std::cout << "double: -nan" << std::endl;
		return ;
	}
}
