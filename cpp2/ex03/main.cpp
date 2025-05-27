#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const A, Point const B, Point const C, Point const M);

int main( void ) {

	Point A(0.0f, 1.0f);
	Point B(1.0f, 0.0f);
	Point C(0.0f, 0.0f);
	Point M(0.5f, 0.5f);
	if (bsp(A, B, C, M)) {
		std::cout << "Point M is inside the triangle ABC" << std::endl;
	}
	else {
		std::cout << "Point M is outside the triangle ABC" << std::endl;
	}

	return 0;
}
