#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; i++)
	{
		int num;
		std::stringstream ss(argv[i]);
		if (ss >> num && num > 0) {
			vec.push_back(num);
			deq.push_back(num);
		} else {
			std::cout << "Error" << std::endl;
			return 1;
		}
	}

	PmergeMe sorter;

	std::cout << "Before: ";
	sorter.printContainer(vec);

	sorter.sortVector(vec);
	std::cout << "After: ";
	sorter.printContainer(vec);

	std::cout << "Before: ";
	sorter.printContainer(deq);

	sorter.sortDeque(deq);
	std::cout << "After: ";
	sorter.printContainer(deq);
	return 0;
}
