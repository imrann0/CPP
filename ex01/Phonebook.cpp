#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->i = 0;
	std::cout << "Phonebook Başlatıldı i = " << i << std::endl;
}


void Phonebook::print_contact(Contact contact)
{
	std:: cout << "Name:         " << contact.get_name() << " | ";
	std:: cout << "Surname:      " << contact.get_surname() << " | ";
	std:: cout << "Nick Name:    " << contact.get_nick_name() << " | ";
	std:: cout << "Phone Number: " << contact.get_phone_number() << " | ";
	std:: cout << "Secret:       " << contact.get_secret() << std::endl;
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
		if (!name.empty())
			con.set_name(name);
		else
			std::cout << "Name cannot be empty" << std::endl;
	}
	while (surname.empty())
	{
		std::cout << "Surname: ";
		std::getline(std::cin, surname);
		if (!surname.empty())
			con.set_surname(surname);
		else
			std::cout << "Surname cannot be empty" << std::endl;
	}
	while (nickname.empty())
	{
		std::cout << "Nick Name: ";
		std::getline(std::cin, nickname);
		if (!nickname.empty())
			con.set_nick_name(nickname);
		else
			std::cout << "Nick Name cannot be empty" << std::endl;
	}
	while (number.empty())
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, number);
		if (!number.empty())
			con.set_phone_number(number);
		else
			std::cout << "Phone Number cannot be empty" << std::endl;
	}
	while (secret.empty())
	{
		std::cout << "Secret: ";
		std::getline(std::cin, secret);
		if (!secret.empty())
			con.set_secret(secret);
		else
			std::cout << "Secret cannot be empty" << std::endl;
	}
	this->con[this->i % 8] = con;
	this->i++;
	//std::cout <<"Name: " << name <<" " << surname <<" " << nickname <<" " << number <<" " << secret<< std::endl;
}

void Phonebook::Search()
{
	int j;
	std::string num;

	j = 0;
	if (this->i == 0 && 0)
		std::cout << "Phonebook empty" << std::endl;
	else
	{
		std::cout << "Phonebook İd: ";
		std::getline(std::cin, num);
		if (num.length() > 1 || num.compare("8") > 0 || num.compare("0") < 0)
			std::cout << "Hatalı İnput" << std::endl;
		else
			j = std::atoi(num.c_str());
	}

	if (j != 0 && j <= this->i)
	{
		print_contact(this->con[j - 1]);
	}
	else // NE DURUMDA hepsi listelencek kesin bir koşul yok
	{
		j = 0;
		while(this->i > j)
		{
			print_contact(this->con[j]);
			j++;
		}
	}
}
