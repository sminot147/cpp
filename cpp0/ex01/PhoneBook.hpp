/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:19:39 by sminot            #+#    #+#             */
/*   Updated: 2025/05/15 13:34:06 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <cstdlib>
# include <iomanip>

class PhoneBook
{
public :
	//canonique
	PhoneBook();
	PhoneBook(const PhoneBook &phonebook);
	PhoneBook &operator=(const PhoneBook &phonebook);
	~PhoneBook();

	//other
	void add_contact();
	void search_contact();

private :
	Contact _contacts[8];
	int _index;
	int _size;
};

#endif