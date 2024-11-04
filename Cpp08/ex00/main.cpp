#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i + 2);


	try
	{
		std::cout << *easyfind(v, 11);
		std::cout << *easyfind(v, 32);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
