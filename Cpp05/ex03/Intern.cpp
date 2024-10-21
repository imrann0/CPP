#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intetn Constructor Called." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" <<std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern Copy Construcor Called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &opt)
{
	std::cout << "Intern Assignation operator called" << std::endl;
	if (this == &opt)
		return *this;

	return *this;
}

static AForm* makePresident(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

static AForm* makeRobot(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* makeShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}


AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (*all_forms[])(const std::string&) = {&makePresident, &makeRobot, &makeShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "Intern Can Not Create A Form Called " << form << std::endl;
	return (NULL);
}


