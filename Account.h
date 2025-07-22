#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

// Base class
class Account
{
    // Comment 1: Since << is a non-member operator, we should declare it as
    //            friend in order to access member variables of the Account class.
    friend std::ostream &operator<<(std::ostream &, const Account &);
public:
    Account(double initialBalance);

    void credit(double addMoney);
    bool debit(double withdrawMoney);
    double getBalance() const;

    Account &operator+=(const double& addMoney);
    Account &operator-=(const double& withdrawMoney);
    Account operator+(const double& addMoney) const;
    Account operator-(const double& withdrawMoney) const;
    Account &operator=(const Account&);
private:
    double balance;
};

// Comment 2: Non-member function will return a new Account object.
Account operator+(const double& addMoney, const Account& account);

#endif