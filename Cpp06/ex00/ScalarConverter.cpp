
#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src) { (void)src; return (*this); }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
	double value = 0.0;

	if (isChar(literal))
		value = static_cast<double>(literal[0]);
	else if (isInt(literal))
		value = static_cast<double>(std::atoi(literal.c_str()));
	else if (isFloat(literal))
		value = std::strtof(literal.c_str(), NULL);
	else if (isDouble(literal))
		value = std::strtod(literal.c_str(), NULL);
	else {
		std::cout << "Invalid literal" << std::endl;
		return;
	}

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
	char* end;

	long result = std::strtol(literal.c_str(), &end, 10);
	return *end == '\0' && result >= std::numeric_limits<int>::min() && result <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	return literal.find('f') != std::string::npos && literal[literal.length() - 1] == 'f';
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	char* end;

	std::strtod(literal.c_str(), &end);
	return *end == '\0';
}

void ScalarConverter::displayChar(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::displayInt(double value)
{
	if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::displayFloat(double value)
{

	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::displayDouble(double value)
{
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}
