/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:56:23 by sminot            #+#    #+#             */
/*   Updated: 2025/05/23 14:20:24 by sminot           ###   ########.fr       */
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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int				 _value;
	static const int _bitToFloat = 8;
};

#endif