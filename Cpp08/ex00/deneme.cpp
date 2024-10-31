#include <algorithm>
#include <array>
#include <vector>
#include <iostream>


int main()
{
	std::cout << "Arrayler\n";
	std::array<int, 3> sayilar = {10, 20, 30};
	std::reverse(sayilar.begin(), sayilar.end());
	//sayilar.fill(1); -> tüm diziyi 1'le doldurur.
	for (int i = 0; i < sayilar.size(); i++)
	{
		std::cout << sayilar[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Vektörler\n";
	std::vector<std::string> kisiler;
	//kisiler.resize(10);

	for (int i = 0; i < 5; i++)
		kisiler.push_back(std::to_string(i));
	// kisiler.erase( std::remove(kisiler.begin(), kisiler.end(), "2"), kisiler.end());
	for (int i = 0; i < kisiler.size(); i++)
		std::cout << kisiler[i] << " ";
	std::cout << "\n";
	std::cout << "Size: "<< kisiler.size() << " Capacity: " << kisiler.capacity() << std::endl;


	std::vector<int> sayi;
	sayi.push_back(1);
	sayi.push_back(2);
	sayi.push_back(3);
	sayi.push_back(4);
	sayi.push_back(5);
	sayi.push_back(6);
	sayi.push_back(2);
	sayi.push_back(7);

	std::cout << "Vektör öncesi: ";
	for (int i = 0; i < sayi.size(); i++)
	{
		std::cout << sayi[i] << " ";
	}
	std::cout << std::endl;

	// Yalnızca std::remove kullanıyoruz
	//std::remove(sayi.begin(), sayi.end(), 2);
	//std::cout << "Vektör sonrası sadece remove ile: ";
  	sayi.insert(sayi.begin() + 2, 11);
	for (int i = 0; i < sayi.size(); i++)
	{
		std::cout << sayi[i] << " ";
	}
	std::cout << std::endl;
}
