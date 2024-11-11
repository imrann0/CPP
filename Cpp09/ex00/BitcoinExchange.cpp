#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

int trim(std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (first == std::string::npos)
	{
		str = "";
		return 1;
	}
	size_t last = str.find_last_not_of(' ');
	if (first == 0 && last == str.size() - 1)
		return 0;
	str = str.substr(first, last - first + 1);
	return 1;
}


BitcoinExchange::BitcoinExchange(): _data()
{
	std::ifstream input;
	std::string	line;

	input.open("data.csv");
	if (!input.good())
		throw BitcoinExchange::FileOpenException();
	std::getline(input, line);
	if (line != "date,exchange_rate")
		throw BitcoinExchange::InvalidArgumentException();
	while (std::getline(input, line))
	{
		char *end;
		std::string date;
		std::string value = line.substr(line.find(",") + 1, line.length());
		std::strtod(value.c_str(), &end);
		if (*end == '\0')
		{
			date = line.substr(0, line.find(","));
			double number = std::strtod(value.c_str(), NULL);
			this->_data.insert(std::pair<std::string, double>(date, number));
		}
		else
			throw BitcoinExchange::InvalidArgumentException();
	}
}

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _data(copy._data) {}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &opt)
{
	if (this != &opt)
		_data = opt._data;
	return *this;
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
	std::string date, value, line;
	char *end;
	double number;

	input.open(file.c_str());
	if (!input.good())
		throw BitcoinExchange::FileOpenException();
	std::getline(input, line);
	trim(line);
	if (line != "date | value")
		throw BitcoinExchange::InvalidArgumentException();
	while (std::getline(input, line))
	{
		size_t separator =  line.find(" | ");
		if (separator != std::string::npos)
		{
			date = line.substr(0, separator);
			value = line.substr(separator + 3);
			trim(date);
			validateDateFormat(date);
			std::strtod(value.c_str(), &end);
			if (*end == '\0')
			{
				number = std::strtod(value.c_str(), &end);
				if (number < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else
				{
					if (number > 1000)
						std::cout << "Error: too large a number." << std::endl;
					else
					{
						it a = _data.lower_bound(date);

						if (a == _data.begin()) {
							std::cout << "No data found before the given date." << std::endl;
						} else
						{
							if (a->first != date)
								--a;
							std::cout << date << " => " << number << " = ";
							std::cout << a->second * number << std::endl;
						}
					}
				}
			}
			else
				std::cout << "Error Invalid Number" << std::endl;
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
	}
}

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


void verifyDateValidity(size_t year, size_t month, size_t day)
{
	if (year > 2022 || year < 2009)
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (month > 12 || month < 1)
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (day < 1)
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (year == 2009 && month == 1 && day == 1)
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (year == 2022 && month > 3)
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (year == 2022 && month == 3 && day > 29)
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			if (day > 29)
				std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
		}
		else if (day > 28)
			std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (day > 31)
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
}


void validateDateFormat(std::string date)
{
	std::string year, month, day;

	size_t firstDash = date.find("-");
	year = date.substr(0, firstDash);
	size_t secondDash = date.find("-", firstDash + 1);
	month = date.substr(firstDash + 1, secondDash - firstDash - 1);
	day = date.substr(secondDash + 1);
	if (trim(year) || trim(month) || trim(day))
		throw BitcoinExchange::InvalidArgumentException();
	if (!IsNumeric(year) || !IsNumeric(month) || !IsNumeric(day))
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
	verifyDateValidity(std::atoi(year.c_str()), std::atoi(month.c_str()), std::atoi(day.c_str()));
}
