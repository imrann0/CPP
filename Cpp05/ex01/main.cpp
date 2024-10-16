#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Form a("A",100, 50);
		Bureaucrat b("bob", 110);

		a.beSigned(b);
		b.signForm(a);
		std::cout << a.getIsSigned() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}


}
