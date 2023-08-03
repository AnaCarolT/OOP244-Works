/***********************************************************************
// Final Project Milestone 4
// Module: Book
// Filename: Book.h
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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include "Publication.h"

namespace sdds {
	//The Book class is derived from the Publication class. A book is a publication with an "Author name".
	class Book : public Publication {
		//The book class only has one attribute that is a pointer to a character to hold an author's name Dynamically.
		char* m_author{};

	public:

		//Construction
		Book();

		//The rule of three
		Book(const Book& book); //copy constructor
		Book& operator=(const Book& book); //copy assignment
		~Book(); //destructor

		//Methods
		//The book class overrides the following virtual methods and type conversion operator.
		//type
		char type() const;
		//write
		std::ostream& write(std::ostream& os) const;
		//read
		std::istream& read(std::istream& is);
		//set
		void set(int member_id);
		//operator bool()
		operator bool() const;
	};
}
#endif // !SDDS_BOOK_H



