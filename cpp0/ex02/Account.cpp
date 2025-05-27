/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:25:19 by sminot            #+#    #+#             */
/*   Updated: 2025/05/15 17:01:09 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>


/*----------------------------------------------------------------------------*/
/*                               Static                                       */
/*----------------------------------------------------------------------------*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*----------------------------------------------------------------------------*/
/*                               Display Inforamtion                          */
/*----------------------------------------------------------------------------*/


void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm* t = std::localtime(&now);

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", t);
	std::cout << buffer << " ";
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount
		<< ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}


/*----------------------------------------------------------------------------*/
/*                              Init and destructor                           */
/*----------------------------------------------------------------------------*/

Account::Account(int initial_deposit) :
	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

/*----------------------------------------------------------------------------*/
/*                               Getter                                       */
/*----------------------------------------------------------------------------*/


int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int	 Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int	 Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int	 Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}


/*----------------------------------------------------------------------------*/
/*                                   Other                                    */
/*----------------------------------------------------------------------------*/

void Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << ++this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawal:" << ++this->_nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}