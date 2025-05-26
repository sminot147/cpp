#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void)
: _x(0), _y(0)
{}

Point::Point(const Point& src) 
: _x(src._x), _y(src._y)
{}


Point& Point::operator=(const Point& rhs) {
	if (this != &rhs){
		std::cout << "You cannot assign  new value to a const Point !" << std::endl;
	}
	return *this;
}

Point::~Point(void) {
}


Point::Point(const float x, const float y)
: _x(Fixed(x)), _y(Fixed(y)) 
{}

Fixed Point::getX(void) const {
	return _x;
}

Fixed Point::getY(void) const {
	return _y;
}