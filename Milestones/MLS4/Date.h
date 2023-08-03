// Final Project Milestone 4 
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ana Tirolli        2023-07-08           Implementing code
// 
// -----------------------------------------------------------
// 
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
// 
/////////////////////////////////////////////////////////////////

#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>

namespace sdds {

   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int  DAY_ERROR = 4;
   const char DATE_ERROR[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
   };

   const int  MIN_YEAR = 1500;

   /* The date class encapsulates the following values :

   - Year; an integer between the year 1500 till today
   - Month, an integer between 1 and 12
   - Day, an integer between 1 and the number of days in the month.
   - Error code; an integer that holds the code that corresponds to an error that recently happened or ZERO if the date object is valid and ready to be used.
   - Current year; an integer that is automatically initialized to the current date of the system for validation purposes when a Date object is instantiated.*/

   class Date {
   private:
      int m_year;
      int m_mon;
      int m_day;
      int m_ErrorCode;
      int m_CUR_YEAR;
      int daysSince0001_1_1()const; // returns number of days passed since the date 0001/1/1
      bool validate();             /* validates the date setting the error code and then returning the result 
                                    true, if valid, and false if invalid.*/
      void errCode(int);           // sets the error code
      int systemYear()const;       // returns the current system year
      bool bad()const;             // return true if
      int mdays()const;            // returns the number of days in current month
      void setToToday();           // sets the date to the current date (system date)
   public:
      Date();                      // creates a date with current date
      Date(int year, int mon, int day); /* create a date with assigned values
                                         then validates the date and sets the 
                                         error code accordingly */
      int errCode()const;         // returns the error code or zero if date is valid
      const char* dateStatus()const;  // returns a string corresponding the current status of the date
      int currentYear()const;         // returns the m_CUR_YEAR value;     
      //TO DO:

      //Streams:
      std::istream& read(std::istream& is = std::cin); //This function reads a date from the console in the following format YYYY/MM/DD.
      std::ostream& write(std::ostream& os = std::cout)const; //This write/print the date.

      //Operators:
      bool operator==(const Date& other) const;// 0 or 1, equal
      bool operator!=(const Date& other) const;// 0 or 1, not equal
      bool operator>=(const Date& other) const;// 0 or 1, greater or rqual
      bool operator<=(const Date& other) const;// 0 or 1, lesser or equal
      bool operator<(const Date& other) const; // 0 or 1, lesser
      bool operator>(const Date& other) const; // 0 or 1, higher
      int operator-(const Date& other) const; //needs to be int because it needs to return the value of the calculation
      operator bool() const; // 0 or 1, validate the date

   };
   std::ostream& operator<<(std::ostream& os, const Date& RO); //write
   std::istream& operator>>(std::istream& is, Date& RO); //read
   //to work globally
   extern bool sdds_test;
   extern int sdds_year;
   extern int sdds_mon;
   extern int sdds_day;
}
#endif