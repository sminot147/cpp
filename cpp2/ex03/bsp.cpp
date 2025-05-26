#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>





bool bsp( Point const A, Point const B, Point const C, Point const M){
	Point AB(B.getX().toFloat() - A.getX().toFloat(), B.getY().toFloat() - A.getY().toFloat());
	Point BC(C.getX().toFloat() - B.getX().toFloat(), C.getY().toFloat() - B.getY().toFloat());
	Point CA(A.getX().toFloat() - C.getX().toFloat(), A.getY().toFloat() - C.getY().toFloat());
	
}