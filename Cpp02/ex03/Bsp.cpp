#include "Point.hpp"
#include <iostream>
#include <cmath>

Fixed	triangleArea(Point const a, Point const b, Point const c)
{
	Fixed bc = a.getX() * (b.getY() - c.getY());
	Fixed ca = b.getX() * (c.getY() - a.getY());
	Fixed ab = c.getX() * (a.getY() - b.getY());

	Fixed area = (bc + ca + ab) / Fixed(2.0f);
	return (area.abs());
}


bool bsp(Point const a,Point const b,Point const c,Point const point)
{
	Fixed abc = triangleArea(a, b, c);
	Fixed pbc = triangleArea(point, b, c);
	Fixed apc = triangleArea(a, point, c);
	Fixed abp = triangleArea(a, b, point);

	std::cout << "31 " << abc << " " << pbc << " " << apc << " " << abp << std::endl;
	if (abc == (pbc + apc + abp))
		std::cout << "31 Ulas" << std::endl;
	else
		std::cout << "31 asfaf" << std::endl;
	return (true);
}
