/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:00:28 by sminot            #+#    #+#             */
/*   Updated: 2025/05/17 14:16:42 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name){

	if (N <= 0)
		return NULL;

	Zombie* Horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		Horde[i].set_name(name);
	}
	return Horde;
}