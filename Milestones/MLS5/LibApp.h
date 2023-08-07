/***********************************************************************
// Final Project Milestone 5
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
#include "Publication.h"

namespace sdds {

   class LibApp {

	   //Add an array of 256 characters to hold the publication data file name.
	   char m_filename[SDDS_TITLE_MAX_LENGTH + 1]{};

	   //This array will be populated with all the records of the publication data file when the LibApp is instantiated.
	   Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{};

	   //Add an integer to hold the number of Publications loaded into the PPA.
	   int m_NOLP;

	   //Add an integer to hold the last library reference number read from the data file.
	   int m_LLTR;

	   //A flag to keep track of changes made
	   bool m_changed;

	   //main menu of the application
	   Menu m_mainMenu;

	   //exit menu content
	   Menu m_exitmenu;

	   //Add a Menu to the LibApp for selection of publication type.
	   Menu m_publicationmenu;

	   //past milestones
	   bool confirm(const char* message);
	   void load(); //message
	   void save(); //message
	   int search(int state = 1); //message
	   void returnPub(); //message
	   void newPublication(); //message
	   void removePublication(); //message
	   void checkOutPub(); //message
	   //MLS 5
	   Publication* getPub(int libRef)const;

   public:
	   LibApp(const char* fileName);
	   void run(); //main menu
	   //avoid memory leak
	   virtual ~LibApp();
   };
}
#endif // !SDDS_LIBAPP_H



