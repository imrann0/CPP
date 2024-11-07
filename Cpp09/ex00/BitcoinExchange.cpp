#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

bool IsNumeric(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}


void DateCheckControl(size_t year, size_t month, size_t day)
{
	if (year > 2022 || year < 2009)
		std::cout << "Hata2" << std::endl;
	else if (month > 12 || month < 0)
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (year == 2009 && month == 1 && day == 1)
		std::cout << "Hata" << std::endl;
	else if (year == 2022 && month > 3)
		std::cout << "Hata1" << std::endl;
	else if (year == 2022 && month == 3 && day > 29)
		std::cout << "Hata3" << std::endl;
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day > 29)
				std::cout << "Hata: Şubat 29 günden fazla olamaz" << std::endl;
		}
		else if (day > 28)
			std::cout << "Hata: Şubat 28 günden fazla olamaz" << std::endl;
	}
}


void DateCheck(std::string date)
{
	std::string year, month, day;

	size_t firstDash = date.find("-");
	year = date.substr(0, firstDash);
	size_t secondDash = date.find("-", firstDash + 1);
	month = date.substr(firstDash + 1, secondDash - firstDash - 1);
	day = date.substr(secondDash + 1);
	if (!IsNumeric(year) || !IsNumeric(month) || !IsNumeric(day))
		throw BitcoinExchange::InvalidArgumentException();
	DateCheckControl(std::atoi(year.c_str()), std::atoi(month.c_str()), std::atoi(day.c_str()));

	/*std::cout << "Year: " << year << std::endl;
	std::cout << "Month: " << month << std::endl;
	std::cout << "Day: " << day << std::endl;*/
}


BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default Constructor Called" << std::endl;

	std::ifstream input;
	std::string	line;
	size_t	rule = 0;

	input.open("data.csv");
	if (!input.good())
		throw BitcoinExchange::FileOpenException();
	while (std::getline(input, line))
	{
		char *end;
		std::string date;
		std::string value = line.substr(line.find(",") + 1, line.length());
		std::strtod(value.c_str(), &end);
		if (*end == '\0')
		{
			if (rule == 0)
			{
				rule += 1;
				std::cout << "Başlangıç Değerleri Verilmedi" << std::endl;
			}
			date = line.substr(0, line.find(","));
			DateCheck(date);
			double number = std::strtod(value.c_str(), NULL);
			this->_data.insert(std::pair<std::string, double>(date, number));
		}
		else if (rule >= 1)
			throw BitcoinExchange::InvalidArgumentException();
		else
			rule += 1;
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

void	BitcoinExchange::ReadInput(std::string file)
{
	std::ifstream	input;
	std::string		line;

	input.open(file);
	if (!input.good())
		throw BitcoinExchange::FileOpenException();
	std::getline(input, line);
	if (line != "date | value")
		throw BitcoinExchange::InvalidArgumentException();
	while (std::getline(input, line))
	{
		char	*end;
		std::string date, value;

		value = line.substr(line.find(",") + 1, line.length());
		date = line.substr(0, line.find(","));
		std::strtod(value.c_str(), &end);
		//std::cout << date << std::endl;
		std::cout << end << std::endl;
		if (*end == '\0')
		{
			//std::cout << date << std::endl;
			DateCheck(date);
		}

	}
}
