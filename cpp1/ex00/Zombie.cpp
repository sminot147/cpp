/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:06:22 by sminot            #+#    #+#             */
/*   Updated: 2025/05/17 20:29:15 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

std::string randomName(void)
{
	std::string name;
	int nb_letter = std::rand() % 3 + 4;
	for (int i = 0; i < nb_letter; i++)
	{
		name += rand() % 26 + 'a';
	}
	name[0]=std::toupper(name[0]);
	return name;
}


Zombie::Zombie() :
_name(randomName())
{
	std::cout << "Zombie " << _name << " as been created" << std::endl;
}

Zombie::Zombie(std::string name) :
_name(name)
{
	std::cout << "Zombie " << _name << " as been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " as been destroy" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}