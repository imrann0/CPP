#include "easyfind.hpp"
#include <iostream>
int main()
{
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);


	try
	{
		std::cout << *easyfind(v, 11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
