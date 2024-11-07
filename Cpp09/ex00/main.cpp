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
			//test.print();
		}
		catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
	}
	else
		std::cerr << "Error: could not open file." << std::endl;




	/*std::map<std::string, double> b;
	b.insert(std::make_pair("asfas", 12.0));
	std::map<std::string, double>::iterator a = b.begin();
	std::cout << b["asfas"] << std::endl;
	std::cout << a->first << std::endl;
	std::cout << a->second << std::endl;*/
}
