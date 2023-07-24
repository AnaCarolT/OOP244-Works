/***********************************************************************
// Final Project Milestone 2
// Module: LibApp
// Filename: LibApp.h
// Version 1.0
// Author	Ana Tirolli
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
// -----------------------------------------------------------
//
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"

namespace sdds {

   class LibApp {
	   //A flag to keep track of changes made
	   bool m_changed;
	   //main menu of the application
	   Menu m_mainMenu;
	   //exit menu content
	   Menu m_exitmenu;
	   bool confirm(const char* message);
	   void load(); //message
	   void save(); //message
	   void search(); //message
	   void returnPub(); //message
	   void newPublication(); //message
	   void removePublication(); //message
	   void checkOutPub(); //message
   public:
	   LibApp(); //constructor
	   void run(); //main menu
   };
}
#endif // !SDDS_LIBAPP_H



