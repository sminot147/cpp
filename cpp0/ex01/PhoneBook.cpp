/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:19:36 by sminot            #+#    #+#             */
/*   Updated: 2025/05/15 13:33:51 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*---------------------------------------------------------------------------*/
/*                               Canonique                                   */
/*---------------------------------------------------------------------------*/
PhoneBook::PhoneBook() :
	_index(0), _size(0)
{}

PhoneBook::PhoneBook(const PhoneBook &phonebook) :
	_index(phonebook._index), _size(phonebook._size)
{
	for (int i = 0; i < this->_index; i++)
		this->_contacts[i] = phonebook._contacts[i];
}

PhoneBook &PhoneBook::operator=(const PhoneBook &src)
{
	if (this != &src){
		this->_index = src._index;
		this->_size = src._size;
		for (int i = 0; i < this->_index; i++)
			this->_contacts[i] = src._contacts[i];
	}
	return *this;
}

PhoneBook::~PhoneBook()
{}

/*---------------------------------------------------------------------------*/
/*                               Other                                       */
/*---------------------------------------------------------------------------*/

void PhoneBook::add_contact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	if (firstName.empty() || lastName.empty() || nickname.empty() ||
		phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "All fields must be filled" << std::endl;
		return ;
	}
	if (this->_index < 8)
	{
		this->_contacts[this->_size] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
		this->_index++;
		this->_size++;
	}
	else
	{
		this->_contacts[this->_index % 8] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
		if (this->_index >= 15) {this->_index -= 8;}
		this->_index++;
	}
}

/**
 * @brief Truncate a string to a maximum length of 10 characters.
 * If the string is longer than 10 characters, it will be truncated to 9 characters
 * and a dot will be added at the end.
 * @param str The string to be truncated.
 * @return The truncated string.
 */
std::string truncate(const std::string str)
{
	std::string str_trunc = str;
	if (str_trunc.length() > 10)
	{
		str_trunc = str_trunc.substr(0, 9);
		str_trunc += ".";
	}
	return str_trunc;
}

void PhoneBook::search_contact()
{
	if (this->_index == 0)
	{
		std::cout << "No contacts in the phonebook" << std::endl;
		return ;
	}
	for (int i = 0; i < this->_index; i++)
	{
		std::cout << "Contact number " << i << " :";
		std::cout << std::setw(10) << truncate(this->_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) <<  truncate(this->_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) <<  truncate(this->_contacts[i].getNickname()) << std::endl;
	}
	std::string line;
	std::cout << "Enter the number of the contact you want to view : ";
	std::getline(std::cin, line);
	if ('0' <= line[0] && line[0] <= '7' && line[1] == '\0'){
		int number = line[0] - '0';
		if (this->_size <= number){
			std::cout << "Contact does not exist" << std::endl;}
		else {
			std::cout<<this->_contacts[number];}
	}
	else {
		std::cout<<"Invalid number"<<std::endl;
		return ;
	}
}
