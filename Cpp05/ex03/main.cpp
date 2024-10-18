#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib> // rand()
#include <ctime>   // time()

int main()
{
	std::srand(std::time(0));
	try
	{
		ShrubberyCreationForm k("benagacım");
		RobotomyRequestForm b("a");
		Bureaucrat l("bob", 150);
		std::cout << std::endl;
		b.beSigned(l);
		b.execute(l);
		b.execute(l);
		std::cout << std::endl;
		k.beSigned(l);
		k.execute(l);
		std::cout << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
