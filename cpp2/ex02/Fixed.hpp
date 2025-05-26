/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:56:23 by sminot            #+#    #+#             */
/*   Updated: 2025/05/26 11:23:38 by sminot           ###   ########.fr       */
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

private:
	int				 _value;
	static const int _bitToFloat = 8;

};

 std::ostream & operator<<(std::ostream &o, Fixed const & contact);

#endif