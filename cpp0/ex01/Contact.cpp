/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:00:22 by sminot            #+#    #+#             */
/*   Updated: 2025/05/13 14:25:30 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*---------------------------------------------------------------------------*/
/*                               Canonique                                   */
/*---------------------------------------------------------------------------*/

Contact::Contact() :
	_firstName(""), _lastName(""), _nickname(""),
	_phoneNumber(""), _darkestSecret("")
{}

Contact::Contact(const Contact &contact) :
	_firstName(contact._firstName), _lastName(contact._lastName),
	_nickname(contact._nickname), _phoneNumber(contact._phoneNumber),
	_darkestSecret(contact._darkestSecret)
{}

Contact &Contact::operator=(const Contact &src){
	if (this != &src) {
		this->_firstName = src._firstName;
		this->_lastName = src._lastName;
		this->_nickname = src._nickname;
		this->_phoneNumber = src._phoneNumber;
		this->_darkestSecret = src._darkestSecret;
	}
	return *this;
}

Contact::~Contact()
{}



/*---------------------------------------------------------------------------*/
/*                              Constructeur                                 */
/*---------------------------------------------------------------------------*/

Contact::Contact(std::string firstName, std::string lastName, std::string nickname,
	std::string phoneNumber, std::string darkestSecret) :
_firstName(firstName), _lastName(lastName), _nickname(nickname),
_phoneNumber(phoneNumber), _darkestSecret(darkestSecret)
{}



/*---------------------------------------------------------------------------*/
/*                                setter                                     */
/*---------------------------------------------------------------------------*/

void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void	Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}



/*---------------------------------------------------------------------------*/
/*                                getter                                     */
/*---------------------------------------------------------------------------*/

std::string	Contact::getFirstName() const {
	return this->_firstName;
}

std::string	Contact::getLastName() const {
	return this->_lastName;
}

std::string	Contact::getNickname() const {
	return this->_nickname;
}

std::string	Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return this->_darkestSecret;
}

std::ostream &	operator<<(std::ostream &o, Contact const & contact) {
	o << "First name: " << contact.getFirstName() << std::endl;
	o << "Last name: " << contact.getLastName() << std::endl;
	o << "Nickname: " << contact.getNickname() << std::endl;
	o << "Phone number: " << contact.getPhoneNumber() << std::endl;
	o << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	return o;
}

