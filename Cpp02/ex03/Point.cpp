#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	std::cout << "Point Default Constructor Called" << std::endl;
}

Point::Point(float const x, const float y): _x(x), _y(y)
{
	std::cout << "Point Float Constructor Called" << std::endl;
}

Point::Point(Point const &point)
{
	std::cout << "Point Copy Constructor Called" << std::endl;
	this->_x = point._x;
	this->_y = point._y;
}
Point& Point::operator=(Point const &a)
{
	std::cout << "Point Copy Assignment Operator Called" << std::endl;
	if (this != &a)
	{
		this->_x = a.getX();
		this->_y = a.getY();
	}
	return *this;
}

Point::~Point()
{
	std::cout << "Point Destructor Called" << std::endl;
}

Fixed Point::getX() const { return (_x);}

Fixed Point::getY() const {return (_y);}
