#include <iostream>
#include "Array.hpp"

int main() {
	try {
		Array<int> emptyArray;
		std::cout << "Boş dizinin boyutu: " << emptyArray.size() << std::endl;

		unsigned int n = 5;
		Array<int> filledArray(n);
		std::cout << "5 elemanlı dizinin boyutu: " << filledArray.size() << std::endl;

		std::cout << "Varsayılan eleman değerleri:" << std::endl;
		for (unsigned int i = 0; i < filledArray.size(); ++i) {
			std::cout << "filledArray[" << i << "] = " << filledArray[i] << std::endl;
		}

		std::cout << "Eleman ataması yapılıyor:" << std::endl;
		for (unsigned int i = 0; i < filledArray.size(); ++i) {
			filledArray[i] = i * 2;
		}

		std::cout << "Atanan değerler:" << std::endl;
		for (unsigned int i = 0; i < filledArray.size(); ++i) {
			std::cout << "filledArray[" << i << "] = " << filledArray[i] << std::endl;
		}

		Array<int> copyArray(filledArray);
		std::cout << "Kopyalanmış dizinin boyutu: " << copyArray.size() << std::endl;

		copyArray[0] = 100;
		std::cout << "filledArray[0] (orijinal): " << filledArray[0] << std::endl;
		std::cout << "copyArray[0] (kopya): " << copyArray[0] << std::endl;

		Array<int> assignedArray;
		assignedArray = filledArray;
		std::cout << "Atama yapılmış dizinin boyutu: " << assignedArray.size() << std::endl;

		assignedArray[1] = 200;
		std::cout << "filledArray[1] (orijinal): " << filledArray[1] << std::endl;
		std::cout << "assignedArray[1] (atama yapılmış): " << assignedArray[1] << std::endl;

		std::cout << "Sınır dışı erişim testi:" << std::endl;
		std::cout << filledArray[10] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Hata: " << e.what() << std::endl;
	}

	return 0;
}
