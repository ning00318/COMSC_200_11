#include <iostream>
#include <iomanip>
#include "Account.h" // Account class definition
#include "SavingsAccount.h" // SavingsAccount class definition
#include "CheckingAccount.h" // CheckingAccount class definition
using namespace std;

int main()
{
   Account account1( 1000.0 ); // create Account object
   SavingsAccount account2( 1500.0, 0.03 ); // create SavingsAccount object
   CheckingAccount account3( 3000.0, 15.0 ); // create CheckingAccount object

   cout << fixed << setprecision( 2 );

   // display initial balance of each object
   cout << "account1 balance: $" << account1 << endl;
   cout << "account2 balance: $" << account2 << endl;
   cout << "account3 balance: $" << account3 << endl;

   // -= operator
   cout << "\naccount1 -= $500.0..." << endl;
   account1 -= 500.0; // try to debit $500.00 from account1
   cout << "\naccount2 -= $300.0..." << endl;
   account2 -= 300.0; // try to debit 300.00 from account2
   cout << "\naccount3 -= $1500.0..." << endl;
   account3 -= 1500.0; // try to debit $1500.00 from account3

   // display balances
   cout << "\naccount1 balance: $" << account1 << endl;
   cout << "account2 balance: $" << account2 << endl;
   cout << "account3 balance: $" << account3 << endl;

   // += operator
   cout << "\naccount1 += $600.0..." << endl;
   account1 += 600.0; // credit $600.00 to account1
   cout << "\naccount2 += $700.0..." << endl;
   account2 += 700.0; // credit $700.00 to account2
   cout << "\naccount3 += $400.0..." << endl;
   account3 += 400.0; // credit $400.00 to account3

   // display balances
   cout << "\naccount1 balance: $" << account1 << endl;
   cout << "account2 balance: $" << account2 << endl;
   cout << "account3 balance: $" << account3 << endl;

   // add interest to SavingsAccount object account2
   double interestEarned = account2.calculateInterest();
   cout << "\nAdding $" << interestEarned << " interest to account2." << endl;
   cout << "account2 + $" << interestEarned << "..." << endl;
   account2 = account2 + interestEarned;  // Member function operator+

   cout << "\nNew account2 balance: $" << account2<< endl;

   // Non-member function operator+
   cout << "\n$10.0 + account1..." << endl;
   account1 = 10.0 + account1;
   cout << "\n$70.0 + account2..." << endl;
   account2 = 70.0 + account2;
   cout << "\n$85.0 + account3..." << endl;
   account3 = 85.0 + account3;

   // display balances
   cout << "\naccount1 balance: $" << account1 << endl;
   cout << "account2 balance: $" << account2 << endl;
   cout << "account3 balance: $" << account3 << endl;

   // - operator
   cout << "\naccount1 - $20.0..." << endl;
   account1 = account1 - 20.0;
   cout << "\naccount2 - $60.0..." << endl;
   account2 = account2 - 60.0;
   cout << "\naccount3 - $120.0..." << endl;
   account3 = account3 - 120.0;

   // display balances
   cout << "\naccount1 balance: $" << account1 << endl;
   cout << "account2 balance: $" << account2 << endl;
   cout << "account3 balance: $" << account3 << endl;
   system("PAUSE");
   return 0;
   
}