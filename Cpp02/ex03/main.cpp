#include "Point.hpp"
bool bsp(Point const a,Point const b,Point const c,Point const point);

int main()
{
	Point a(0,0);
	Point b(5,0);
	Point c(0,5);
	Point d(2.6,2.5);

	if (bsp(a,b,c,d) == false)
	{
		std::cout << "not inside the triangle." << std::endl;
	}
	else
		std::cout << "Inside the triangle." << std::endl;
}
