#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Account.h"

// Derived class
class CheckingAccount : public Account
{
    friend std::ostream &operator<<(std::ostream &, const CheckingAccount &);
public:
    CheckingAccount(double initialBalance, double fee);
    void credit(double addMoney);
    void debit(double withdrawMoney);

    CheckingAccount &operator+=(const double& addMoney);
    CheckingAccount &operator-=(const double& withdrawMoney);
    CheckingAccount operator+(const double& addMoney) const;
    CheckingAccount operator-(const double& withdrawMoney) const;
    CheckingAccount &operator=(const CheckingAccount&);
private:
    double transactionFee;
};

#endif