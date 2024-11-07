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
		std::cout << "Error0: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (month > 12 || month < 1)
		std::cout << "Error1: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (day < 1)
		std::cout << "Error7: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (year == 2009 && month == 1 && day == 1)
		std::cout << "Error2: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (year == 2022 && month > 3)
		std::cout << "Error3: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (year == 2022 && month == 3 && day > 29)
		std::cout << "Error4: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{ // Artık yıl kontrolü
			if (day > 29)
				std::cout << "Error5: bad input => " << year << "-" << month << "-" << day << std::endl;
		} else if (day > 28)
		{
			std::cout << "Error6: bad input => " << year << "-" << month << "-" << day << std::endl;
		}
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		std::cout << "Error7: bad input => " << year << "-" << month << "-" << day << std::endl;
	else if (day > 31)
		std::cout << "Error8: bad input => " << year << "-" << month << "-" << day << std::endl;
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
		std::cout << "Error8: bad input => " << year << "-" << month << "-" << day << std::endl;
	DateCheckControl(std::atoi(year.c_str()), std::atoi(month.c_str()), std::atoi(day.c_str()));
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
			//DateCheck(date);
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
	std::string date, value, line;
	char *end;
	double number;

	input.open(file);
	if (!input.good())
		throw BitcoinExchange::FileOpenException();
	std::getline(input, line);
	if (line != "date | value")
		throw BitcoinExchange::InvalidArgumentException();

	while (std::getline(input, line))
	{
		size_t separator =  line.find(" | ");
		if (separator != std::string::npos)
		{
			date = line.substr(0, separator);
			value = line.substr(separator + 3);
			DateCheck(date);
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
						// lower_bound ile belirtilen tarihten büyük veya eşit ilk tarihe ulaşılır
						it a = _data.lower_bound(date);

						// Eğer it == _data.begin() ise, geçmişte hiçbir veri yok demektir
						if (a == _data.begin()) {
							std::cout << "No data found before the given date." << std::endl;
						} else {
							// Eğer it, aradığımız tarihten daha büyükse bir önceki elemana kay
							if (a->first != date) {
								--a;
							}
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
