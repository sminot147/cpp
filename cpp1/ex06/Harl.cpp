/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:20:15 by sminot            #+#    #+#             */
/*   Updated: 2025/05/20 14:05:15 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) const {
	std::cout << "[ DEBUG ]\n";
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void) const {
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void) const {
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) const {
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) const {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	std::string* begin = levels;
	std::string* end = levels + sizeof(levels) / sizeof(std::string);
	
	int nb_of_complain = -1;
	for (std::string* it = begin; it != end; ++it) {
		if (level == *it){
			nb_of_complain = it - begin;
		}
	}
	switch (nb_of_complain) {
		case -1 :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		case 0 :
			this->debug();
		case 1 :
			this->info();
		case 2 :
			this->warning();
		case 3 :
			this->error();
	}
}
