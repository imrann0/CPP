#include "Form.hpp"
#include <iostream>

int main()
{
	Form a(100, 50);
	Bureaucrat b("bob", 100);

	a.beSigned(b);
	std::cout << a.getStatus() << std::endl;
}
