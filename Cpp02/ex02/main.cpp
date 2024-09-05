#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	/*Fixed a (10);
	Fixed b(10);
	if (a > b)
		std::cout << "31" << std::endl;
	else
		std::cout << "!31" << std::endl;
	if (b < a)
		std::cout << "32" << std::endl;
	else
		std::cout << "!32" << std::endl;
	if (b >= a)
		std::cout << "33" << std::endl;
	else
		std::cout << "!33" << std::endl;
	if (b <= a)
		std::cout << "34" << std::endl;
	else
		std::cout << "!34" << std::endl;
	if (b != a)
		std::cout << "35" << std::endl;
	else
		std::cout << "!35" << std::endl;
	if (b == a)
		std::cout << "35" << std::endl;
	else
		std::cout << "!35" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;*/

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
