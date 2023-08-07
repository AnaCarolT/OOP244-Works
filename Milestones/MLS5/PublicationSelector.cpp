// Final Project 
// PublicationSelector
// File PublicationSelector.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PublicationSelector.h"
using namespace std;
namespace sdds {
    //Display the list of publications starting from the specified page
   void PublicationSelector::display(int page) const {
       //header
      cout << m_title << endl 
           << " Row  |LocID | Title                          |Mem ID | Date       | Author          |" << endl
           << "------+------+--------------------------------+-------+------------+-----------------|" << endl;
      //loop through all the information that needs to be printed in a specific format
      for (int i = (page - 1) * m_pageSize ; i < m_noOfPubs && i < page * m_pageSize; i++) {
         cout.width(4);
         cout.setf(ios::right);
         cout.fill(' ');
         cout << (i + 1);
         cout.unsetf(ios::right);
         cout << "- " << *m_pub[i] << endl;
      }
   }
   //get the library reference number of the selected publication 
   int PublicationSelector::getSelectedLibRef()const{
      bool ok{};
      char newline{};
      char chPeek{};
      int val{};
      int retVal{};
      //provide options for navegation
      if (m_noOfPubs > m_pageSize) {
         if (m_currentPage > 1) 
            cout << "> P (Previous Page)" << endl;
         if (m_currentPage * m_pageSize < m_noOfPubs) 
            cout << "> N (Next page)" << endl;
      }
      cout << "> X (to Exit)" << endl << "> Row Number(select publication)" << endl;
      cout << "> ";
      do {
         chPeek = cin.peek();
         switch (chPeek) {
         case 'P':
         case 'p':
            cin.ignore(1000, '\n');
            retVal = 2;  // previous page
            if (m_currentPage > 1)
               ok = true;
            else
               ok = false;
            break;
         case 'N':
         case 'n':
            cin.ignore(1000, '\n');
            retVal = 1; // Next page
            if (m_currentPage * m_pageSize < m_noOfPubs)
               ok = true;
            else
               ok = false;
            break;
         case 'X':
         case 'x':
            cin.ignore(1000, '\n');
            retVal = 0; // Exit
            ok = true;
            break;
         default:
            cin >> val;
            newline = cin.get();
            if (cin.fail() || newline != '\n') {
               ok = false;
               cin.clear();
               cin.ignore(1000, '\n');
            }
            else {
               ok = val >= 1 && val <= m_noOfPubs;
               if(ok) retVal = m_pub[val - 1]->getRef();
            }
            break;
         }
      } while (!ok && cout << "Invalid selection, retry" << endl << "> ");
      return retVal; //reference number
   }
   PublicationSelector::~PublicationSelector() {
      delete[] m_pub; //avoid memory leak
   }
   PublicationSelector::PublicationSelector(const char* title, int pageSize) :m_pageSize{ pageSize } {
       //constructor to initialize the object
      strncpy(m_title, title, 80);
      m_title[80] = 0;
      m_pub = new const Publication*[m_arraySize = allocationUnit];
   }
   PublicationSelector& PublicationSelector::operator<<(const Publication& pub) {
       //add a publication to the selector
      return operator<<(&pub);
   }
   PublicationSelector& PublicationSelector::operator<<(const Publication* pub) {
       //add publication pointer to the selector
      if (m_noOfPubs == m_arraySize) {
         const Publication** temp = new const Publication*[m_arraySize += allocationUnit];
         for (int i = 0; i < m_noOfPubs; i++) {
            temp[i] = m_pub[i];
         }
         delete[] m_pub;
         m_pub = temp;
      }
      m_pub[m_noOfPubs++] = pub;
      return *this;
   }

   void PublicationSelector::reset() {
       //set to default
      delete[] m_pub;
      m_pub = new const Publication*[20];
      m_noOfPubs = 0;
   }
   int PublicationSelector::run() {
       //run the publication selection process 
      int retVal{};
      do {
          //display list of publications
         display(m_currentPage);
         retVal = getSelectedLibRef();
         if (retVal && retVal < 3) {
            if (retVal == 2) retVal = -1;
            m_currentPage += retVal;
            //if (m_currentPage == 0) 
            //   m_currentPage = 1; // don't go before first page
            //else if (m_currentPage * m_pageSize > m_noOfPubs) //((m_currentPage-1) * m_pageSize > m_noOfPubs) 
            //   m_currentPage = m_noOfPubs/m_pageSize +1; // don't go after last page
         }
      } while (retVal && retVal < 3);
      return retVal;
   }
   
   void PublicationSelector::sort() {
       //used to sort
      int i, j;
      const Publication* temp{};
      for (i = 0; i < m_noOfPubs - 1; i++) {
         for (j = 0; j < m_noOfPubs - i - 1; j++) {
            if (m_pub[j]->checkoutDate() > m_pub[j + 1]->checkoutDate()) {
               temp = m_pub[j];
               m_pub[j] = m_pub[j + 1];
               m_pub[j + 1] = temp;
            }
         }
      }
      for (i = 0; i < m_noOfPubs - 1; i++) {
         for (j = 0; j < m_noOfPubs - i - 1; j++) {
            if (strcmp((const char*)*m_pub[j], (const char*)*m_pub[j + 1]) > 0 ) {
               temp = m_pub[j];
               m_pub[j] = m_pub[j + 1];
               m_pub[j + 1] = temp;
            }
         }
      }
   }

   PublicationSelector::operator bool()const {
       //used to check if there is publications
      return m_noOfPubs > 0;
   }
}
