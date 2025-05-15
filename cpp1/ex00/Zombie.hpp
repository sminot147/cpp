/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:52:48 by sminot            #+#    #+#             */
/*   Updated: 2025/05/15 18:06:19 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie{

public :
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );
	
	void announce( void )

private :
	std::string name;
	static int nb_Zombie;
}

#endif