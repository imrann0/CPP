#include <iostream>
#include "Phonebook.hpp"

int	main(void)
{
	Phonebook book;
	std::string str;

	while(str != "EXIT")
	{
		std::cout << "Değer Giriniz: (ADD)" << std::endl;
		std::getline(std::cin, str);
		if (str == "ADD")
			book.Add();
		else if (str == "SEARCH")
			book.Search();
		else
			std::cout << "Girilen Değer Yok Lütfen Tekrear Deneyiniz" << std::endl;
	}
}
