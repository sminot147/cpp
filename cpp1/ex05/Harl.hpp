/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:20:18 by sminot            #+#    #+#             */
/*   Updated: 2025/05/20 14:05:33 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl {

public:
	void complain(std::string level) const;

private:
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;
};

#endif
