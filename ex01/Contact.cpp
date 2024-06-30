#include "Contact.hpp"

std::string Contact::get_first_name(void)
{
	return (this->first_name);
}


void	Contact::set_first_name(std::string name)
{
	this->first_name = name;
}
