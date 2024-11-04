#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>


BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default Constructor Called" << std::endl;

	std::ifstream input;
	std::string	line;
	size_t	rule = 0;

	input.open("d.csv");
	if (!input.good())
		std::cout << "file could not be opened" << std::endl; // throw Atılması Lazım
	while (std::getline(input, line))
	{
		char *end;
		std::string date;
		std::string value = line.substr(line.find(",") + 1, line.length());

		std::strtod(value.c_str(), &end);
		if (*end == '\0')
		{
			date = line.substr(0, line.find(","));
			double number = std::stod(value);
			this->_data.insert(std::make_pair(date, number));
		}
		else
		{
			rule += 1;
			std::cout << "asfas" << std::endl;
		}


	}

}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default Destructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	(void)copy;
	std::cout << "Copy Constructor Called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &opt)
{
	(void)opt;
	std::cout << "Copy Assignment Operator Called" << std::endl;
	return (*this);
}

void	BitcoinExchange::print()
{
	it begin = _data.begin();

	for (; begin != _data.end(); begin++)
		std::cout << begin->first << "," << begin->second << std::endl;
}

