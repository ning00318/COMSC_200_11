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

// Comment 3: Because we already defined credit(), in the overloaded operator function +=,
//            it will invoke the credit() and return the updated object.
Account &Account::operator+=(const double& addMoney)
{
    credit(addMoney);
    return *this;
}

// Comment 4: Because we already defined debit(), in the overloaded operator function -=,
//            it will invoke the debit() and return the updated object.
Account &Account::operator-=(const double& withdrawMoney)
{
    debit(withdrawMoney);
    return *this;
}

// Comment 5: In the overloaded operator function +, we create a new Account object to avoid
//            modifying the original object, then invoke the credit() and return the updated balance.
Account Account::operator+(const double& addMoney) const
{
    Account result(balance);
    result.credit(addMoney);
    return result;
}

// Comment 6: In the overloaded operator function -, we create a new Account object to avoid
//            modifying the original object, then invoke the debit() and return the updated balance.
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

// Comment 7: Member functions will only work when the class object is on the left side. In this
//            case, using a non-member function can deal with the expression like 50.0 + account A.
Account operator+(const double& addMoney, const Account& account)
{
    Account result = account;
    result += addMoney;
    return result;
}

std::ostream &operator<<(std::ostream &output, const Account &account)
{
    output << account.getBalance();
    return output;
}