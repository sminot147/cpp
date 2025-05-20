/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:20:21 by sminot            #+#    #+#             */
/*   Updated: 2025/05/20 14:05:09 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
	
	Harl harl;
	
	if (ac == 1)
	{
		std::cout<< "Harl thinking about his next complain" <<std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++){
		harl.complain(av[i]);
	}

	return 0;
}
