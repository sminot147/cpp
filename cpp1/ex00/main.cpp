/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:16 by sminot            #+#    #+#             */
/*   Updated: 2025/05/17 13:49:29 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <ctime>
#include <cstdlib>


Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void){

	//initialisation du random
	std::srand(time(0));

	{
		Zombie Pierre("Pierre");
		Pierre.announce();
	}
	{
		Zombie* Zombie_bis = newZombie("Hello");
		Zombie_bis->announce();
		delete Zombie_bis;
	}
	{
		std::cout << "Zombie random : ";
		Zombie Random;
		Random.announce();
		std::cout << std::endl;
		std::cout << "Zombie random 2 : ";
		Zombie Random2;
		Random2.announce();
		std::cout << std::endl;
	}
	{
		randomChump("Albert");
	}
}