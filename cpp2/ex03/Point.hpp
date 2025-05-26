#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

public:
	// Canonical Form
	Point();
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	
	// Other Constructors
	Point(const float x, const float y);

	// Getters
	Fixed getX(void) const;
	Fixed getY(void) const;

private:
	const Fixed _x;
	const Fixed _y;
};

#endif