/***********************************************************************
// Final Project Milestone 3
// Module: Publication
// Filename: Publication.h
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

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include <iostream>
#include <cstring>
#include "Streamable.h"
#include "Date.h"
#include "Lib.h"


namespace sdds {

	class Publication : public Streamable {

		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN + 1]; //plus null terminator
		int m_membership;
		int m_libRef;
		Date m_date;

	public:
		//default constructor
		Publication(); 

		//copy constructor
		Publication(const Publication& publi);

		//assigment operator
		Publication& operator=(const Publication& publi);

		//destructor
		~Publication();

		// Sets the membership attribute to either zero or a five-digit integer.
		virtual void set(int member_id); 

		// Sets the **libRef** attribute value
		void setRef(int value);

		// Sets the date to the current date of the system.
		void resetDate();

		//Returns the character 'P' to identify this object as a "Publication object"
		virtual char type()const;

		//Returns true is the publication is checkout (membership is non-zero)
		bool onLoan()const;

		//Returns the date attribute
		Date checkoutDate()const;

		//Returns true if the argument title appears anywhere in the title of the publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		bool operator==(const char* title)const;

		//Returns the title attribute
		operator const char* ()const;

		//Returns the libRef attribute.
		int getRef()const;

		//Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
		bool conIO(std::ios& io) const;

		//read and write
		//output, cant change
		std::ostream& write(std::ostream& os) const;
		//input, can change
		std::istream& read(std::istream& is);
		//operator bool
		//Returns true if neither of the title or shelfId attributes is null or empty. Otherwise, it will return false.
		operator bool() const;
	};
}

#endif // !SDDS_PUBLICATION_H



