#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) // initialising the private me
// mebers when the object is created and constructor is called
{
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "Index:" << _accountIndex
              << ";amount:" << _amount
              << ";created"
              << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "Index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed"
              << std::endl;
    _nbAccounts --;
    _totalAmount -= _amount;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
    std::time_t current_time = std::time(NULL);         //  Used null to indicate the current time
    std::tm *localTime = std::localtime(&current_time); // is a structure that holds time information broken down into human-readable components
    char Buffer[20];

    std::strftime(Buffer, sizeof(Buffer), "[%Y%m%d_%H%M%S]", localTime);
    std::cout << Buffer;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << checkAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << checkAmount()
              << ";deposit:" << deposit
              << ";amount:" << checkAmount() + deposit
              << ";nb_deposits:" << _nbDeposits + 1
              << std::endl;

    _amount += deposit;
    _nbDeposits = +1;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex
                  << ";amount:" << checkAmount()
                  << ";withdrawal:refused" << std::endl;
        return (false);
    }
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << checkAmount()
              << ";withdrawal:" << withdrawal
              << ";amount:" << checkAmount() - withdrawal
              << ";nb_withdrawals:" << _nbWithdrawals + 1
              << std::endl;
    _amount -= withdrawal;
    _nbWithdrawals  = +1;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return(true);
}
