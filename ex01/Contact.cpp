#include "Contact.hpp"

std::string Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string Contact::get_nick_name(void)
{
	return (this->nick_name);
}

std::string Contact::get_phone_number(void)
{
	return (this->pohne_number);
}

void	Contact::set_first_name(std::string name)
{
	this->first_name = name;
}

void	Contact::set_last_name(std::string last)
{
	this->last_name = last;
}

void	Contact::set_nick_name(std::string nick)
{
	this->nick_name = nick;
}

void	Contact::set_phone_number(std::string phone)
{
	this->pohne_number = phone;
}
