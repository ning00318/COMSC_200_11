#include <iostream>
#include "SavingsAccount.h"
using namespace std;

SavingsAccount::SavingsAccount(double initialBalance, double initialInterest)
    : Account(initialBalance), interestRate(initialInterest)
{
}

double SavingsAccount::calculateInterest() const
{
    return interestRate * Account::getBalance();
}

SavingsAccount &SavingsAccount::operator+=(const double& addMoney)
{
    credit(addMoney);
    return *this;
}

SavingsAccount &SavingsAccount::operator-=(const double& withdrawMoney)
{
    debit(withdrawMoney);
    return *this;
}

// Comment 8: In the overloaded operator function +, we create a new SavingsAccount object to avoid modifying the original
//            object, remember to add a parameter for the interest rate, then invoke the credit() and return the updated balance.
SavingsAccount SavingsAccount::operator+(const double& addMoney) const
{
    SavingsAccount result(getBalance(), interestRate);
    result.credit(addMoney);
    return result;
}

SavingsAccount SavingsAccount::operator-(const double& withdrawMoney) const
{
    SavingsAccount result(getBalance(), interestRate);
    result.debit(withdrawMoney);
    return result;
}

// Comment 9: In the overloaded operator function =, we assign a savings account with another savings account
//            named account2 through the operator function from the class Account and return the result.
SavingsAccount &SavingsAccount::operator=(const SavingsAccount& account2)
{
    Account::operator=(account2);
    return *this;
}

SavingsAccount operator+(const double& addMoney, const SavingsAccount& account)
{
    SavingsAccount result = account;
    result += addMoney;
    return result;
}

std::ostream &operator<<(std::ostream &output, const SavingsAccount &account)
{
    output << account.getBalance();
    return output;
}