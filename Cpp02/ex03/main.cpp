#include "Point.hpp"
bool bsp(Point const a,Point const b,Point const c,Point const point);

int main()
{
	Point a(0,0);
	Point b(5,0);
	Point c(0,5);
	Point d(2.5,2.5);
	bsp(a,b,c,d);

	//std::cout << b.getX();
	//std::cout << b.getY() << std::endl;
}
