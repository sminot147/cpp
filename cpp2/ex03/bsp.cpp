#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>






bool bsp( Point const A, Point const B, Point const C, Point const M){
	Point AB(B.getX().toFloat() - A.getX().toFloat(), B.getY().toFloat() - A.getY().toFloat());
	Point AC(C.getX().toFloat() - A.getX().toFloat(), C.getY().toFloat() - A.getY().toFloat());
	Point AM(M.getX().toFloat() - A.getX().toFloat(), M.getY().toFloat() - A.getY().toFloat());
	
	
	Fixed det = AB.getX() * AC.getY() - AB.getY() * AC.getX();
	
	if (det == 0)
		return false;
	
	Fixed One(1);
	Fixed a = (One / det)*(AC.getY() * AM.getX() - AC.getX() * AM.getY());
	Fixed b = (One / det)*(AB.getX() * AM.getY() - AB.getY() * AM.getX());
	return (a > 0 && b > 0 && (a + b) < 1);
}