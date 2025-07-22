#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

// Derived class
class SavingsAccount : public Account
{
    friend std::ostream &operator<<(std::ostream &, const SavingsAccount &);
public:
    SavingsAccount(double initialBalance, double initialInterest);
    double calculateInterest() const;

    SavingsAccount &operator+=(const double& addMoney);
    SavingsAccount &operator-=(const double& withdrawMoney);
    SavingsAccount operator+(const double& addMoney) const;
    SavingsAccount operator-(const double& withdrawMoney) const;
    SavingsAccount &operator=(const SavingsAccount&);
private:
    double interestRate;
};

SavingsAccount operator+(const double& addMoney, const SavingsAccount& account);

#endif