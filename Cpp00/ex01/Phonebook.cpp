#include "Phonebook.hpp"
#include <iomanip>
#include <unistd.h>

Phonebook::Phonebook()
{
	this->i = 0;
	std::cout << "Phonebook Launched i = " << i << std::endl;
}


void Phonebook::print_contact()
{
	int i;

	i = 0;
	std::cout << std::setw(10) << std::left << "ID"<< "|";
	std::cout << std::setw(10) << std::left << "Name" << "|";
	std::cout << std::setw(10) << std::left << "Surname" << "|";
	std::cout << std::setw(10) << std::left << "Nick" << "|";
	std::cout << std::setw(10) << std::left << "Phone" << std::endl;

	while (i < this->i && i < 8)
	{
		std::cout << std::setw(10) << std::left << i + 1 << "|";
		if (con[i].get_name().length() > 10)
			std::cout << con[i].get_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << std::left << this->con[i].get_name() << "|";
		if (con[i].get_surname().length() > 10)
			std::cout << con[i].get_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << std::left << this->con[i].get_surname() << "|";
		if (con[i].get_nick_name().length() > 10)
			std::cout << con[i].get_nick_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << std::left << this->con[i].get_nick_name() << "|";
		if (con[i].get_phone_number().length() > 10)
			std::cout << con[i].get_phone_number().substr(0, 9) << "." << std::endl;
		else
			std::cout << std::setw(10) << std::left << this->con[i].get_phone_number() << std::endl;
		i++;
	}
}

void Phonebook::print_id(Contact con)
{
	std::cout << "Name: " << con.get_name() << std::endl;
	std::cout << "Surname: " << con.get_surname() << std::endl;
	std::cout << "Nick Name: " << con.get_nick_name() << std::endl;
	std::cout << "Phone Number: " << con.get_phone_number() << std::endl;
	std::cout << "Secret: " << con.get_secret() << std::endl;
}

void Phonebook::Add()
{
	Contact		con;
	std::string	name;
	std::string	surname;
	std::string	nickname;
	std::string	number;
	std::string	secret;

	while (name.empty())
	{
		std::cout << "Name: ";
		std::getline(std::cin, name);
		if (std::cin.eof())
		{
			std::cout << "\nControl ^D Exiting phonebook" << std::endl;
			return ;
		}
		if (!name.empty())
			con.set_name(name);
		else
			std::cout << "Name cannot be empty" << std::endl;
	}
	while (surname.empty())
	{
		std::cout << "Surname: ";
		std::getline(std::cin, surname);
		if (std::cin.eof())
		{
			std::cout << "\nControl ^D Exiting phonebook" << std::endl;
			return ;
		}
		if (!surname.empty())
			con.set_surname(surname);
		else
			std::cout << "Surname cannot be empty" << std::endl;
	}
	while (nickname.empty())
	{
		std::cout << "Nick Name: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
			std::cout << "\nControl ^D Exiting phonebook" << std::endl;
			return ;
		}
		if (!nickname.empty())
			con.set_nick_name(nickname);
		else
			std::cout << "Nick Name cannot be empty" << std::endl;
	}
	while (number.empty())
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, number);
		if (std::cin.eof())
		{
			std::cout << "\nControl ^D Exiting phonebook" << std::endl;
			return ;
		}
		if (!number.empty())
			con.set_phone_number(number);
		else
			std::cout << "Phone Number cannot be empty" << std::endl;
	}
	while (secret.empty())
	{
		std::cout << "Secret: ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
		{
			std::cout << "\nControl ^D Exiting phonebook" << std::endl;
			return ;
		}
		if (!secret.empty())
			con.set_secret(secret);
		else
			std::cout << "Secret cannot be empty" << std::endl;
	}
	this->con[this->i % 8] = con;
	this->i++;
}

void Phonebook::Search(void)
{
	int j;
	std::string num;
	j = 0;
	if (this->i == 0)
		std::cout << "Phonebook empty" << std::endl;
	else
		print_contact();
	if (this->i != 0)
	{
		while(num.empty())
		{
			std::cout << "Phonebook İd: ";
			std::getline(std::cin, num);
			if (std::cin.eof())
			{
				std::cout << "Control ^D Exiting phonebook" << std::endl;
				return ;
			}
			else if (num.empty() || num.length() > 1 || num.compare("8") > 0 || num.compare("0") < 0)
				std::cout << "Please enter a value between 1 and 8" << std::endl;
			else
			{
				j = std::atoi(num.c_str());
				if (j != 0 && j <= this->i)
				{
					print_id(this->con[j  - 1]);
					return ;
				}
				else
					std::cout << "Invalid ID" << std::endl;
			}
			num.clear();
		}
	}
}
