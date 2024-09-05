#include "Fixed.hpp"
#include <iostream>
int main()
{
	/*
		Shallow Copy: Varsayılan kopya yapıcının yaptığı bit-bit kopyalama işlemidir.
		Bu, pointerlar gibi kaynakları yönetirken sorunlara yol açabilir.

		Deep Copy: Kendi kopya yapıcınızıanı tmlayarak yapılan, kaynakların
		kendilerini kopyalayan kopyalama işlemidir. Genellikle dinamik bellek yönetimi
		gerektiren durumlarda tercih edilir.

		Ortodoks Kanonik Sınıf Formu
	*/

	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
