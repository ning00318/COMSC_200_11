#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(double initialBalance)
    : balance(initialBalance)
{
    if (balance < 0.0)
    {
        balance = 0.0;
        cout << "The initial balance was invalid." << endl;
    }
}

void Account::credit(double addMoney)
{
    balance += addMoney;
}

bool Account::debit(double withdrawMoney)
{
    if (withdrawMoney <= balance)
    {
        balance -= withdrawMoney;
        return true;
    }
    else
    {
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }
}

double Account::getBalance() const
{
    return balance;
}

Account &Account::operator+=(const double& addMoney)
{
    credit(addMoney);
    return *this;
}

Account &Account::operator-=(const double& withdrawMoney)
{
    debit(withdrawMoney);
    return *this;
}

Account Account::operator+(const double& addMoney) const
{
    Account result(balance);
    result.credit(addMoney);
    return result;
}

Account Account::operator-(const double& withdrawMoney) const
{
    Account result(balance);
    result.debit(withdrawMoney);
    return result;
}

Account &Account::operator=(const Account& account2)
{
    balance = account2.balance;
    return *this;
}

std::ostream &operator<<(std::ostream &output, const Account &account)
{
    output << account.getBalance();
    return output;
}