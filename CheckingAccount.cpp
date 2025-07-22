#include <iostream>
#include "CheckingAccount.h"
using namespace std;

CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance), transactionFee(fee)
{
}

void CheckingAccount::credit(double addMoney)
{
    Account::credit(addMoney);
    Account::debit(transactionFee);
    cout << "$" << transactionFee << " transaction fee charged." << endl;
}

void CheckingAccount::debit(double withdrawMoney)
{
    if (Account::debit(withdrawMoney))
    {
        Account::debit(transactionFee);
        cout << "$" << transactionFee << " transaction fee charged." << endl;
    }
}

CheckingAccount &CheckingAccount::operator+=(const double& addMoney)
{
    credit(addMoney);
    return *this;
}

CheckingAccount &CheckingAccount::operator-=(const double& withdrawMoney)
{
    debit(withdrawMoney);
    return *this;
}

CheckingAccount CheckingAccount::operator+(const double& addMoney) const
{
    CheckingAccount result(getBalance(), transactionFee);
    result.credit(addMoney);
    return result;
}

CheckingAccount CheckingAccount::operator-(const double& withdrawMoney) const
{
    CheckingAccount result(getBalance(), transactionFee);
    result.debit(withdrawMoney);
    return result;
}

CheckingAccount &CheckingAccount::operator=(const CheckingAccount& account2)
{
    Account::operator=(account2);
    return *this;
}

CheckingAccount operator+(const double& addMoney, const CheckingAccount& account)
{
    CheckingAccount result = account;
    result += addMoney;
    return result;
}

std::ostream &operator<<(std::ostream &output, const CheckingAccount &account)
{
    output << account.getBalance();
    return output;
}