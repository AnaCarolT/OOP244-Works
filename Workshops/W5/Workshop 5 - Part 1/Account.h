/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-15

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      //TO DO
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account& operator=(int numAcc);
      Account& operator=(Account& account);
      Account& operator+=(double balance);
      Account& operator-=(double balance);
      Account& operator<<(Account& account);
      Account& operator>>(Account& account);
   };
   double operator+(const Account& account1, const Account& account2);
   double& operator+=(double& balance, const Account& account);
}
#endif // SDDS_ACCOUNT_H_