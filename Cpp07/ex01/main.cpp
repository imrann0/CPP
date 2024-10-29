#include <iostream>
#include "iter.hpp"

void doubleValue(int &n)
{
	n *= 2;
}

void negate(int &n)
{
	n = -n;
}

void appendExclamation(std::string &s)
{
	s += "!";
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::string arrs[] = {"Hello", "World", "Example"};
	int len = sizeof(arr) / sizeof(arr[0]);

	iter(arr, len, doubleValue);

	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
	iter(arr, len, negate);

	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
	iter(arrs, 3, appendExclamation);

	for (int i = 0; i < 3; i++) {
		std::cout << arrs[i] << " ";
	}

	std::cout << std::endl;
	return 0;
}
