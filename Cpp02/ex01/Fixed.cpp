#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	_value = num * 256;
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(num * 256);
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
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)_value / 256;
}

int		Fixed::toInt(void) const
{
	return (_value / 256);
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}
