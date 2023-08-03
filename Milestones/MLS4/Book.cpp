/***********************************************************************
// Final Project Milestone 4
// Module: Book
// Filename: Book.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

using namespace std;

namespace sdds {

	Book::Book() :Publication() //constructor
	{
		//needs to invoke the constructor from the parent
		m_author = nullptr;
	}

	Book::Book(const Book& book):Publication(book) //copy constructor
	{
		//initialize the variables in publication to a safe state
		//initialize the variables in book to a safe state
		m_author = nullptr;
		if (book.m_author != nullptr) //check if the is no pointer
		{
			m_author = new char[strlen(book.m_author) + 1]; //allocate memory
			strcpy(m_author, book.m_author); //copy with the right space
		}
	}

	Book& Book::operator=(const Book& book)
	{
		//now we can do the standard procedure of operator=
		if (this != &book)
		{
			//call the one in the base parent first
			Publication::operator=(book);
			delete[]m_author; //set to safe state
			m_author = nullptr; //safe state
			if (book.m_author != nullptr) //check if there is no pinter
			{
				m_author = new char[strlen(book.m_author) + 1]; //allocate memory
				strcpy(m_author, book.m_author); //copy it properly
			}
		}
		return *this; //operator= need to return *this
	}

	Book::~Book()
	{
		delete[] m_author; //avoid memory leak
		m_author = nullptr;
	}

	char Book::type() const
	{
		//Returns the character "B".
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const
	{
		int i = 0;
		//First, it will invoke the write of its Base class.
		Publication::write(os);
		//If the incoming argument is a console IO object.
		if (conIO(os))
		{
			//writes a single space
			os << ' ';
			//writes the author's name in SDDS_AUTHOR_WIDTH spaces. If the author's name is longer than the SDDS_AUTHOR_WIDTH value,
			//it will cut it short and writes exactly SDDS_AUTHOR_WIDTH characters.Note that this should not modify the author's name.
			if (strlen(m_author) > SDDS_AUTHOR_WIDTH)
			{
				for ( i = 0; i < SDDS_AUTHOR_WIDTH; i++)
				{
					os << m_author[i]; //it will print character by character until the limit
				}
			}
			else
			{
				os << m_author;
				for (i = 0; i < SDDS_AUTHOR_WIDTH - int(strlen(m_author)); i++)
				{
					os << " "; //it will fill up the spaces
				}
			}
			//writes " |"
			os << " |";
		}
		else
		{
			//If the incoming argument is not a console IO object
			//writes a tab character '\t'
			//writes the author's name
			os << '\t' << m_author;
		}
		//returns the incoming ostream.
		return os;
	}

	std::istream& Book::read(std::istream& is)
	{
	    //First, invoke the read of the Base class.
		Publication::read(is);
		//Free the memory held for the author's name
		delete[] m_author;
		m_author = nullptr;
		//Read the author name in local variables before setting the attribute to any value. (to make it easier lets assume the author's name can not be more than 256 characters)
		char answer_author[SDDS_AUTHOR_MAX_LENGTH + 1] = { '\0' };
		//If the incoming argument is a console IO object
		if (conIO(is))
		{
			//ignore one character(skip the '\n')
			is.ignore(1, '\n');
			//prompt "Author: "
			cout << "Author: ";
            //read the author's name
			is.getline(answer_author, SDDS_AUTHOR_MAX_LENGTH + 1); //prompt and ignore
		}
		else
		{
			//If the incoming argument is not a console IO object
			//ignore the tab character
			is.ignore(1, '\t');
			//read the author's name
			//V ignore and read
			is.get(answer_author, SDDS_AUTHOR_MAX_LENGTH + 1); //here needs to be get or the arrows don't appear
		}
		//Then if the incoming istream object is not in a fail state, dynamically hold the author's name in the char pointer attribute of the book class.
		if (!is.fail())
		{
			m_author = new char[strlen(answer_author) + 1];
			strcpy(m_author,answer_author);
		}
		//At the end return the incoming istream object.
		return is;
	}

	void Book::set(int member_id)
	{
		//invoke the set of the base class to set the member id
		Publication::set(member_id);
		//reset the date to the current date.
		Publication::resetDate();
	}

	Book::operator bool() const
	{
		//return true if the author's name exists and is not empty and the base class's operator bool() has returned true.
		bool ok = false;
		if (m_author && m_author[0] != '\0' && Publication::operator bool())
		{
			ok = true; //It needs to return true in these specifications
		}
		return ok;
	}
}