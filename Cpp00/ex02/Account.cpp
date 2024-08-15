#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}
Account::Account(int initial_deposit) {
	++_nbAccounts;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
		 << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << checkAmount() << ";closed" << std::endl;
}

int	Account::getNbAccounts(void) {return _nbAccounts; }
int Account::getTotalAmount(void) {return _totalAmount;}
int Account:: getNbDeposits(void) {return _totalNbDeposits;}
int Account:: getNbWithdrawals(void) {return _totalNbWithdrawals;}
int Account::checkAmount(void) const { return _amount; }


void Account::_displayTimestamp(void)
{
	time_t c_time = time(NULL);
	struct tm *local = localtime(&c_time);
	std::cout << std::setfill('0') << "["
	<< local->tm_year + 1900
	<< std::setw(2) << local->tm_mon + 1
	<< std::setw(2) << local->tm_mday << "_"
	<< std::setw(2) << local->tm_hour
	<< std::setw(2) << local->tm_min
	<< std::setw(2) << local->tm_sec << "] ";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount()
		 << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
		 << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;

	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposit:" << ++_nbDeposits << std::endl;
	++_totalNbDeposits;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}





