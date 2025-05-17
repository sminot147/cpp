/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:16 by sminot            #+#    #+#             */
/*   Updated: 2025/05/17 14:14:09 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <ctime>
#include <cstdlib>


Zombie* zombieHorde(int N, std::string string_name);

int main(void){

	//initialisation du random
	std::srand(time(0));

	{
		int Nb_Zombie = 5;
		Zombie* Horde = zombieHorde(Nb_Zombie, "Paul");
		for (int i = 0; i < Nb_Zombie; i++) {
			Horde[i].announce();
		}
		delete[] Horde;
	}
	return 0;
}