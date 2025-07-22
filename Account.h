#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

// Base class
class Account
{
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

// Comment: Non-member function will return a new Account object.
Account operator+(const double& addMoney, const Account& account);

#endif