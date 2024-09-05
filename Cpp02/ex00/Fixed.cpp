#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(Fixed const &fix)
{
	std::cout << "Copy Constuctor Called" << std::endl;
	Fixed::operator=(fix);
}

Fixed& Fixed::operator=(Fixed const &fix)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	this->_value = fix.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::	endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	std::cout << "setRawBits member function called" << std::	endl;
}
