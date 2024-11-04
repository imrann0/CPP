#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::vector<int> generateRandomNumbers(int count, int min, int max)
{
	std::vector<int> randomNumbers;

	srand(time(0));

	for (int i = 0; i < count; ++i) {
		int randomNum = min + (rand() % (max - min + 1));
		randomNumbers.push_back(randomNum);
	}

	return randomNumbers;
}

int main()
{
	/*{
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
	}*/
	/*{
		try
		{
			int count = 10000;
			int min = -100000;
			int max = 100000;


			std::vector<int> randomNumbers = generateRandomNumbers(count, min, max);
			Span b(10000);
			b.addNumbers(randomNumbers.begin(), randomNumbers.end());

			std::cout << "Random Numbers: ";
			b.print();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}*/
	{
		try
		{
			int count = 10;
			int min = -100;
			int max = 100;


			std::vector<int> randomNumbers = generateRandomNumbers(count, min, max);
			Span b(10);
			b.addNumbers(randomNumbers.begin(), randomNumbers.end());
			std::cout << "Random Numbers: ";
			b.print();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	return 0;
}
