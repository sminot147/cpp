#include "Fixed.hpp"
#include <cmath>

/*------------------------------------------------------------------------------*/
/*                              Canonical Form                                  */
/*------------------------------------------------------------------------------*/

Fixed::Fixed(void) :
	_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this= src;
}


Fixed& Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src._value;
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}


/*------------------------------------------------------------------------------*/
/*                              Other Constructors                              */
/*------------------------------------------------------------------------------*/

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

/*------------------------------------------------------------------------------*/
/*                            Getters and Setters                               */
/*------------------------------------------------------------------------------*/

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

/*------------------------------------------------------------------------------*/
/*                                  Convert                                     */
/*------------------------------------------------------------------------------*/

float Fixed::toFloat(void) const {
	float nb = this->_value;
	nb = this->_value;
	nb = nb / PowerOfTwo(this->_bitToFloat);
	return nb;
}


int Fixed::toInt( void ) const{
	return (this->_value >> _bitToFloat);
}

/*------------------------------------------------------------------------------*/
/*                       Overload of operator <<                                */
/*------------------------------------------------------------------------------*/

std::ostream &  operator<<(std::ostream &o, Fixed const & fixed) {
	o << fixed.toFloat();
	return o;
}