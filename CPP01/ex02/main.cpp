#include <iostream>
#include <iomanip>

int main()
{
	std::string a = "HI THIS IS BRAIN";
	std::string *stringPTR = &a;
	std::string &stringREF = a;

	std::cout << std::setw(11) << std::left << "a: " << a << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;

	std::cout << std::setw(11) << std::left << "a: " << &a << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;
	std::cout << "stringPTR: " << &stringPTR << std::endl;
}
