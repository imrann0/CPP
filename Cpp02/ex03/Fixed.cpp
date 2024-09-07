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
	*this = fix;
}

Fixed& Fixed::operator=(Fixed const &fix)
{
	std::cout << "Fixed Copy Assignment Operator Called" << std::endl;
	this->_value = fix.getRawBits();
	return (*this);
}

bool Fixed::operator>(Fixed const &fix)		{ return (this->_value > fix._value); }

bool Fixed::operator>=(Fixed const &fix)	{ return (this->_value >= fix._value); }

bool Fixed::operator<(Fixed const &fix)		{ return (this->_value < fix._value); }

bool Fixed::operator<=(Fixed const &fix)	{ return (this->_value <= fix._value); }

bool Fixed::operator==(Fixed const &fix)	{ return (this->_value == fix._value); }

bool Fixed::operator!=(Fixed const &fix)	{return (this->_value != fix._value); }


Fixed Fixed::operator+(Fixed const &fix)	{ return (this->toFloat() + fix.toFloat()); }

Fixed Fixed::operator-(Fixed const &fix)	{ return (this->toFloat() - fix.toFloat()); }

Fixed Fixed::operator*(Fixed const &fix)	{ return (this->toFloat() * fix.toFloat()); }

Fixed Fixed::operator/(Fixed const &fix)	{ return (this->toFloat() / fix.toFloat()); }

Fixed& Fixed::operator++()
{
	++_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++_value;
	return tmp;
}

Fixed& Fixed::operator--()
{
	--_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--_value;
	return tmp;
}

Fixed& Fixed::max(Fixed &fix1, Fixed &fix2)
{
	return fix1.toFloat() > fix2.toFloat() ? fix1 : fix2;
}

const Fixed& Fixed::max(Fixed const &fix1, Fixed const &fix2)
{
	return fix1.toFloat() > fix2.toFloat() ? fix1 : fix2;
}

Fixed& Fixed::min(Fixed &fix1, Fixed &fix2)
{
	return fix1.toFloat() < fix2.toFloat() ? fix1 : fix2;
}

const Fixed& Fixed::min(Fixed const &fix1, Fixed const &fix2)
{
	return fix1.toFloat() < fix2.toFloat() ? fix1 : fix2;
}



int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

float	Fixed::toFloat(void) const { return (float)_value / 256; }

int		Fixed::toInt(void) const { return (_value / 256); }

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}
