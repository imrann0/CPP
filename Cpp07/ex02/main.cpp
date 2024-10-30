#include <iostream>
#include "Array.hpp"

int main()
{
	try {
		Array<int> emptyArray;
		std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

		unsigned int n = 5;
		Array<int> filledArray(n);
		std::cout << "Size of 5 element array: " << filledArray.size() << std::endl;

		std::cout << "Default element values:" << std::endl;
		for (unsigned int i = 0; i < filledArray.size(); ++i) {
			std::cout << "filledArray[" << i << "] = " << filledArray[i] << std::endl;
		}

		std::cout << "Staff assignment is in progress:" << std::endl;
		for (unsigned int i = 0; i < filledArray.size(); ++i) {
			filledArray[i] = i * 2;
		}

		std::cout << "Assigned values:" << std::endl;
		for (unsigned int i = 0; i < filledArray.size(); ++i) {
			std::cout << "filledArray[" << i << "] = " << filledArray[i] << std::endl;
		}

		Array<int> copyArray(filledArray);
		std::cout << "Size of copied directory: " << copyArray.size() << std::endl;

		copyArray[0] = 100;
		std::cout << "filledArray[0] (original): " << filledArray[0] << std::endl;
		std::cout << "copyArray[0] (Copy): " << copyArray[0] << std::endl;

		Array<int> assignedArray;
		assignedArray = filledArray;
		std::cout << "Size of the assigned array:" << assignedArray.size() << std::endl;

		assignedArray[1] = 200;
		std::cout << "filledArray[1] (original): " << filledArray[1] << std::endl;
		std::cout << "assignedArray[1] (appointment made): " << assignedArray[1] << std::endl;

		std::cout << "Out-of-boundary access testing:" << std::endl;
		std::cout << filledArray[10] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
