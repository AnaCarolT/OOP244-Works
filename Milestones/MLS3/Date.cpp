// Final Project Milestone 3 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ana Tirolli        2023-07-08           Implementing code
// Ana Tirolli        2023-07-21           MLS3
// -----------------------------------------------------------
// 
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
// 
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;
#include "Date.h"

namespace sdds {

    //Global variables need to be added
    bool sdds_test = false;
    int sdds_year = 2023;
    int sdds_mon = 12;
    int sdds_day = 25;

   bool Date::validate() {

      errCode(NO_ERROR); //example of how to set code to no error?
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR); //error based on the year
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR); //error based in the month
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR); //error based on the day
      }
      return !bad();
   }

   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 }; //all the monsths and their diffrent days
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;  //validation of the months
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }

   //subtitute for new code
   //from here:
   int Date::systemYear()const {
       int theYear = sdds_year;
       if (!sdds_test) {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           theYear = lt.tm_year + 1900;
       }
       return theYear;
   }

   void Date::setToToday() {
       if (sdds_test) {
           m_day = sdds_day;
           m_mon = sdds_mon;
           m_year = sdds_year;
       }
       else {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           m_day = lt.tm_mday;
           m_mon = lt.tm_mon + 1;
           m_year = lt.tm_year + 1900;
       }
       errCode(NO_ERROR);
   }
   //until here

   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306; //formatting
   }

   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }

   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate(); //checking if the date is valid
   }

   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()]; //return the status/Id of the error
   }

   int Date::currentYear()const {
      return m_CUR_YEAR; //cureent year
   }

   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode; //copying the error
   }
   int Date::errCode()const {
      return m_ErrorCode; //return the error ID
   }

   bool Date::bad()const { //bool return the errors true (1 = cin, 2 = year, 3 = month, 4 = day and anything below this is false
      return m_ErrorCode != 0; 
   }
  
   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os); //call write
   }

   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is); //call read
   }

   //TO DO:
   std::istream& Date::read(std::istream& is)
   {
       errCode(NO_ERROR); //Clears the error code by setting it NO_ERROR
       char slash = '\0'; //Need to initialize 
       is >> m_year; //checking year format first
       is.get(slash); //read the slash

       if (slash != '/')
       {
           errCode(CIN_FAILED); //failed in the reading
           is.clear(); //reset the error flags in a stream
           //"is" is returning 0 and I'm using clear to return as 1
           //Getting a char is getting me stuck in an infinite loop
           //Trying to make it look like !bad()
           //If it's wrong needs new input
       }
       else
       {
           is >> m_mon; //checking month format second
           is.get(slash); //read until the slash

           if (slash != '/')
           {
               errCode(CIN_FAILED); //failed in the reading
               is.clear(); //change stream flag
           }
           else
           {
               is >> m_day;
               validate(); //using the provided code by the professor to see if any of them have a different error. 
           }
       }
       return is; //return 1 if everything went through
   }

   std::ostream& Date::write(std::ostream& os) const
   {
       //If the Date object is in a “bad” state (it is invalid) print the “dateStatus()”.
       if (bad()) {
           os << dateStatus();
       }
       else //Otherwise, the function should write the date in the following format using the ostream object:
       {
           os << setw(4) << setfill('0') << m_year << "/"; //print year ans slash //width and fill space with 0 in case it's necessary
           os << setw(2) << setfill('0') << m_mon << "/"; //print month and slash //cout.fill was making the '0's go overboard
           os << setw(2) << setfill('0') << m_day; //print day
           os << setfill(' '); //Makes sure the padding is set back to spaces from zero
       }

       return os; //Returns the ostream object.
   }

   bool Date::operator==(const Date& other) const
   {
       //the function daysSince0001_1_1() helps calculating the days that have passed so we can use it to the overload
       //help with leap months
       //variations of days depending of the month
       bool ok = false;
       if (daysSince0001_1_1() == other.daysSince0001_1_1())
       {
           ok = true;
       }
       return ok;
   }

   bool Date::operator!=(const Date& other) const
   {
       bool ok = false;
       if (!(*this == other)) //compare "left" to "right", example m_years == other.m_year
       {
           ok = true;
       }
       return ok;
   }

   bool Date::operator>=(const Date& other) const //greater than or equal
   {
       bool ok = false;
       if (daysSince0001_1_1() >= other.daysSince0001_1_1())
       {
           ok = true;
       }
       return ok;
   }

   bool Date::operator<=(const Date& other) const //less than or equal
   {
       bool ok = false;
       if (daysSince0001_1_1() <= other.daysSince0001_1_1())
       {
           ok = true;
       }
       return ok;
   }

   bool Date::operator<(const Date& other) const //less than
   {
       bool ok = false;
       if (daysSince0001_1_1() < other.daysSince0001_1_1())
       {
           ok = true;
       }
       return ok;
   }

   bool Date::operator>(const Date& other) const //higher than
   {
       bool ok = false;
       if (daysSince0001_1_1() > other.daysSince0001_1_1())
       {
           ok = true;
       }
       return ok;
   }

   int Date::operator-(const Date& other) const //minus
   {
       return (daysSince0001_1_1() - other.daysSince0001_1_1()); //need to return the calculation
   }

   Date::operator bool() const //checker to know if it's necessary to get back in the loop or not
   {
       bool ok = false;
       if (!bad()) //checking if it is not positive/has an error
       {
           ok = true;
       }
       return ok;
   }

}
