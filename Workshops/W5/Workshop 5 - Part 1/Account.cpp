/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-15

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {

   void Account::setEmpty() 
   {
      m_number = -1;
      m_balance = 0.0;
   }

   // New account
   Account::Account() 
   {  
      m_number = 0;
      m_balance = 0.0;
   }

   Account::Account(int number, double balance ) 
   {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }

   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const 
   {
       int ok;
       ok = false; //all start not valid
       if (m_number >= 10000 && m_number <=99999 && m_balance >= 0) //based on set empty
       {
           ok = true; //valid
       }
       return ok;
   }

   Account::operator int() const //just return
   {
       return m_number; 
   }

   Account::operator double() const //just return
   {
       return m_balance;
   }

   bool Account::operator~() const 
   {
       int ok;
       ok = false;
       if (m_number == 0) //new account (or not set?)
       {
           ok = true; //new
       }
       return ok;
   }

   Account& Account::operator=(int numAcc) 
   {
       if (m_number != 0) //check if it's not new
       {
           return *this;
       }
       if (m_number != -1 && numAcc != -1) //important, checking if it's not invalid in both ways
       {
           m_number = numAcc; //checking if the value that is going to get in is correct/valid
       }
       else //invalid goes to empty
       {
           setEmpty();
       }
       return *this;
   }

   Account& Account::operator=(Account& account) 
   {
       if (m_number != -1 && account.m_number != -1) //check if the account values are valid
       {
           m_balance = account.m_balance;
           m_number = account.m_number;
           account.m_number = 0; 
           account.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator+=(double balance) 
   {
       if (*this && balance >= 0.0) //the equal is important because new accounts are set to 0
       {
           m_balance += balance; //add
       }
       return *this;
   }

   Account& Account::operator-=(double balance)
   {
       if (*this && balance >= 0.0 && m_balance >= balance)
       {
           m_balance -= balance; //decrease
       }
       return *this;
   }

   Account& Account::operator<<(Account& account) 
   {
       if (*this && &account != this) //see if account is valid then making sure if it's not a new account
       {
           m_balance += account.m_balance; //There<--here goes to
           account.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& account) 
   {
       if (*this && &account != this) 
       {
           account.m_balance += m_balance; //Here goes to-->there
           m_balance = 0.0;
       }
       return *this;
   }

   double operator+(const Account& account1, const Account& account2)
   {
       return account1.operator double() + account2.operator double(); //it needs to sum and return double
   }

   double& operator+=(double& balance, const Account& account)
   {
       balance += double(account); //There<--here goes to (either way const doesnt change)
       return balance; //need to return double
   }

}