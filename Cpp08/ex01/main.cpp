#include "Span.hpp"
#include <iostream>
int main()
{

	try
	{
		Span a(12);

		for (int i = 0; i < 10; i++)
		{
			a.addNumber(i);
		}
		Span b(10);

		b = a;

		b.print();
		std::cout << b.size() << " " << b.capacity() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

}
