#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(float const x, const float y);
		Point(Point const &point);
		Point& operator=(Point const &a);
		~Point();
		Fixed	getX() const;
		Fixed	getY() const;
	private:
		Fixed _x;
		Fixed _y;

};

#endif
