/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:45:30 by sminot            #+#    #+#             */
/*   Updated: 2025/05/17 20:11:06 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void){

	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF= str;

	std::cout << std::setw(35) << "Mermory adresse of string : " << &str << "\n" << \
	std::setw(35) << "Mermory adresse with stringPTR : " << stringPTR << "\n" <<
	std::setw(35) << "Mermory adresse with stringREF : " << &stringREF << std::endl;
	
	std::cout << std::setw(35) << "Value of string : " << str << "\n" << \
	std::setw(35) << "Value of stringPTR : " << *stringPTR << "\n" <<
	std::setw(35) << "Value of stringREF : " << stringREF << std::endl;

	// Other exemple if someone who never do cpp correct me
	
	// {
	// 	std::string x = "HI THIS IS BRAIN";
	// 	std::string y = "Hey2";
	// 	std::string* stringPTR = &x;
	// 	std::cout << "Pointer value : " << stringPTR << std::endl;
	// 	stringPTR = &y;
	// 	std::cout << "Pointer value : " << stringPTR << std::endl;
	// 	*stringPTR = "Hey42";
	// 	std::cout << "We change the value with \'*stringPTR = \"Hey42\"\' : " << *stringPTR << std::endl;
	// 	stringPTR=NULL;
	// 	std::cout << "Pointer can be NULL : " << stringPTR << std::endl;
	// }

	// {
	// 	std::string x = "Hey1";
	// 	std::string y = "Hey2";
	// 	std::string& stringREF= x;
	// 	std::cout << "Reference value : " << stringREF<< std::endl;
	// 	stringREF= y;
	// 	std::cout << "Reference value : " << stringREF<< std::endl;
	// 	stringREF= "Hey42";
	// 	std::cout << "We change the value with \'stringREF= \"Hey42\"\' : " << stringREF << std::endl;
	// 	//ref=&NULL;
	// 	std::cout << "Reference can't be NULL" << std::endl;
	// }
	
}