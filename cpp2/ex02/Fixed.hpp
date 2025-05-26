/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:56:23 by sminot            #+#    #+#             */
/*   Updated: 2025/05/26 13:11:28 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed {

public:
	// Canonical Form
	Fixed();
	Fixed(const Fixed &src);
	Fixed& operator=(const Fixed &src);
	~Fixed();

	//Other Constructors
	Fixed(int intNb);
	Fixed(float nbFloat);

	// Getters and Setters
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	//Convert
	float toFloat( void ) const;
	int toInt( void ) const;

	// Other fonctions
	static Fixed min (Fixed &a, Fixed &b);
	static Fixed min (const Fixed &a, const Fixed &b);
	static Fixed max (Fixed &a, Fixed &b);
	static Fixed max (const Fixed &a, const Fixed &b);

	// Overloaded Operators

	// Arithmetic Operators
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	// Increment and decrement Operators
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	// Comparison Operators	
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

private:
	int				 _value;
	static const int _bitToFloat = 8;

};

 std::ostream & operator<<(std::ostream &o, Fixed const & contact);

#endif