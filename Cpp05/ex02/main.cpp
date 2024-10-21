#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::srand(std::time(0));
	try
	{
		ShrubberyCreationForm rick("Rick");
		PresidentialPardonForm mort("morty");
		RobotomyRequestForm b("a");
		Bureaucrat l("bob", 150);
		std::cout << std::endl;
		b.beSigned(l);
		b.execute(l);
		b.execute(l);
		std::cout << std::endl;
		rick.beSigned(l);
		rick.execute(l);
		std::cout << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
