#ifndef INTERN_HPP
# define INTETN_HPP

#include <iostream>
#include "AForm.hpp"
class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern& operator=(const Intern &opt);

		AForm* makeForm(std::string form, std::string target);
};
# endif
