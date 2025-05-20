/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:20:15 by sminot            #+#    #+#             */
/*   Updated: 2025/05/20 14:05:28 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) const {
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) const {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) const {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) const {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) const {
	void (Harl::*complain[])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	std::string* begin = levels;
	std::string* end = levels + sizeof(levels) / sizeof(std::string);
	
	bool	change = false;
	for (std::string* it = begin; it != end; ++it) {
		if (level == *it){
			(this->*complain[it - begin])();
			change = true;
		}
	}
	if (!change)
	{
		std::cout << "Harl didn't find complain, maybe you're perfect, maybe you just didn't know how Harl work's !" << std::endl;
	}
}
