/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:52:48 by sminot            #+#    #+#             */
/*   Updated: 2025/05/19 20:03:19 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie{

public :
	Zombie();
	Zombie(std::string);
	~Zombie();

	void set_name(std::string);

	void announce( void ) const;

private :
	std::string _name;
};

#endif