/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:05:41 by sminot            #+#    #+#             */
/*   Updated: 2025/05/13 13:21:04 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
public :
	//canonique
	Contact(); 
	Contact(const Contact &contact);
	Contact &operator=(const Contact &contact);
	~Contact();

	//constructeur
	Contact(std::string firstName, std::string lastName, std::string nickname,
		std::string phoneNumber, std::string darkestSecret);

	//setter
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);

	//getter
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

private :
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

std::ostream & operator<<(std::ostream &o, Contact const & contact);

#endif