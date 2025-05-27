/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:00:25 by sminot            #+#    #+#             */
/*   Updated: 2025/05/15 13:12:20 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int ac, char **av) {
	(void)av;
	if (ac != 1) {
		std::cout << "Usage is just: ./phonebook" << std::endl;
		return 1;
	}
	PhoneBook phonebook;
	std::string command;
	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			std::cout << "\nInput closed. Exiting." << std::endl;
			break;
		}
		if (command == "ADD") { phonebook.add_contact();}
		else if (command == "SEARCH") {phonebook.search_contact();}
		else if (command == "EXIT") {break;}
		else { std::cout << "Invalid command." << std::endl;}
	}
	std::cout << "Exiting phonebook." << std::endl;
	return 0;
}
