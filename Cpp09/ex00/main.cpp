#include "BitcoinExchange.hpp"

int main(int ar, char **av)
{
	std::string	file = av[1];

	if (ar == 2)
	{
		try
		{
			BitcoinExchange test;
			test.ReadInput(file);
		}
		catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
	}
	else
		std::cerr << "Error: could not open file." << std::endl;
}
