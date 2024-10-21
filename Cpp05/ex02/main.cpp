#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::srand(std::time(0));
	ShrubberyCreationForm rick("Rick");
	PresidentialPardonForm morty("morty");
	RobotomyRequestForm robot("a");
	try
	{
		Bureaucrat l("bob", 150);
		std::cout << std::endl;


		robot.beSigned(l);
		robot.execute(l);
		l.executeForm(morty);
		std::cout << std::endl;
		morty.execute(l);
		rick.beSigned(l);
		rick.execute(l);
		std::cout << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}
