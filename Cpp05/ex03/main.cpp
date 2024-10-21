#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::srand(std::time(0));
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
