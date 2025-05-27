#include "Fixed.hpp"
#include <cmath>
#include <climits>

/*----------------------------------------------------------------------------*/
/*                              Canonical Form                                */
/*----------------------------------------------------------------------------*/

Fixed::Fixed(void) :
	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = src._value;
}


Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src._value;
	return *this;
}

Fixed::~Fixed(void) {
	//std::cout << "Destructor called" << std::endl;
}


/*----------------------------------------------------------------------------*/
/*                           Other Constructors                               */
/*----------------------------------------------------------------------------*/

int PowerOfTwo(int power){
	return (1 << power);
}

Fixed::Fixed(int intNb) {
	std::cout << "Int constructor called" << std::endl;
	if (intNb >= PowerOfTwo(32 - this->_bitToFloat)){
		std::cout << "The number is too Huge to be correctly save" <<std::endl;
	}
	this->_value = intNb << this->_bitToFloat;
}

Fixed::Fixed(float nbFloat){
	std::cout << "Float constructor called" << std::endl;
	if (nbFloat >= PowerOfTwo(31 - this->_bitToFloat)){
		std::cout << "The number is too Huge to be correctly save" << std::endl;
	}
	this->_value = roundf(nbFloat * (1 << this->_bitToFloat));
}

/*----------------------------------------------------------------------------*/
/*                          Getters and Setters                               */
/*----------------------------------------------------------------------------*/

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

/*----------------------------------------------------------------------------*/
/*                                 Convert                                    */
/*----------------------------------------------------------------------------*/

float Fixed::toFloat(void) const {
	float nb = this->_value;
	nb = this->_value;
	nb = nb / PowerOfTwo(this->_bitToFloat);
	return nb;
}


int Fixed::toInt( void ) const{
	return (this->_value >> _bitToFloat);
}

/*----------------------------------------------------------------------------*/
/*                             Other Functions                                */
/*----------------------------------------------------------------------------*/

Fixed Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

/*----------------------------------------------------------------------------*/
/*                          Overload of operator                              */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                          Arithmetic Operators                              */
/*----------------------------------------------------------------------------*/

Fixed Fixed::operator+(const Fixed &rhs) const {
	int64_t addition = this->_value;
	addition += rhs._value;
	if (addition > INT_MAX || addition < INT_MIN) {
			std::cout << "Warning: Integer overflow in addition" << std::endl;
	}
	Fixed result;
	result.setRawBits(addition);
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	int64_t difference = this->_value;
	difference -= rhs._value;
	if (difference > INT_MAX || difference < INT_MIN) {
			std::cout << "Warning: Integer overflow in subtraction" << std::endl;
	}
	Fixed result;
	result.setRawBits(difference);
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	int64_t product = this->_value;
	product *= rhs._value;
	product = product >> this->_bitToFloat;
	if (product > INT_MAX || product < INT_MIN) {
			std::cout << "Warning: Integer overflow in multiplication" << std::endl;
	}
	Fixed result;
	result.setRawBits(product);
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	int64_t quotient = this->_value;
	if (rhs._value == 0) {
		std::cout << "Warning: Integer division by zero." << std::endl;
		return Fixed(0);
	}
	quotient *= PowerOfTwo(this->_bitToFloat);
	quotient /= rhs._value;
	if (quotient > INT_MAX || quotient < INT_MIN) {
		std::cout << "Warning: Integer overflow in division" << std::endl;
	}
	Fixed result;
	result.setRawBits(quotient);
	return result;
}

/*----------------------------------------------------------------------------*/
/*                    Increment and decrement Operators                       */
/*----------------------------------------------------------------------------*/

Fixed& Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {	// Postfix increment (the int parameter is used to differentiate from pre-increment)
	Fixed temp = *this;
	this->_value++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_value--;
	return temp;
}


/*----------------------------------------------------------------------------*/
/*                         Comparison Operators                               */
/*----------------------------------------------------------------------------*/

bool Fixed::operator>(const Fixed &rhs) const {
	return this->_value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->_value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return this->_value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return this->_value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->_value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return this->_value != rhs._value;
}


/*----------------------------------------------------------------------------*/
/*                              Operators <<                                  */
/*----------------------------------------------------------------------------*/

std::ostream &  operator<<(std::ostream &o, Fixed const & fixed) {
	o << fixed.toFloat();
	return o;
}