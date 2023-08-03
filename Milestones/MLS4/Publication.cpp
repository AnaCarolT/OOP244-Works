/***********************************************************************
// Final Project Milestone 4
// Module: Publication
// Filename: Publication.h
// Version 1.0
// Author	Ana Tirolli
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ana Tirolli     2023-08-02      Giving errors while retrieving input
//
// -----------------------------------------------------------
//
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"

using namespace std;
namespace sdds {

	Publication::Publication():m_shelfId{'\0'}
	{
		m_title = nullptr;
		m_title = NULL;
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
	}

	Publication::Publication(const Publication& publi)
	{
		//do all the procedures for copy constructor
		//initializing all the variables
		m_title = NULL;
		strcpy(m_shelfId, publi.m_shelfId);
		m_membership = publi.m_membership;
		m_libRef = publi.m_libRef;
		m_date = publi.m_date;

		//making sure the title has no pointer
		if (publi.m_title != nullptr)
		{
			m_title = new char[strlen(publi.m_title) + 1]; //lil space for null terminator
			strcpy(m_title, publi.m_title); //copy
		}
	}

	Publication& Publication::operator=(const Publication& publi)
	{
		//initialing all the variables with the values
		strcpy(m_shelfId, publi.m_shelfId);
		m_membership = publi.m_membership;
		m_libRef = publi.m_libRef;
		m_date = publi.m_date;

		if (publi.m_title != nullptr)
		{
			delete[] m_title; //avoid memory leak
			m_title = new char[strlen(publi.m_title) + 1]; //lil space for null terminator
			strcpy(m_title, publi.m_title); //copy
		}
		return *this; //copy assigment always return *this
	}

	Publication::~Publication()
	{
		delete[] m_title;
	}

	void Publication::set(int member_id) {
		//set to 0 if it's more than 5 digits
		if (member_id > 99999) {
			m_membership = 0;
		}
		else {
			//set to the actual number if it's below 5 digits
			m_membership = member_id;
		}
	}

	void Publication::setRef(int value)
	{
		// Sets the **libRef** attribute value
		m_libRef = value; //set
	}

	void Publication::resetDate()
	{
		// Sets the date to the current date of the system.
		m_date = Date(); //Date will pick the setToToday();
	}

	char Publication::type() const
	{
		//Returns the character 'P' to identify this object as a "Publication object"
		return 'P'; //return the P
	}

	bool Publication::onLoan() const
	{
		//Returns true is the publication is checkout (membership is non-zero)
		bool ok = false;
		if (m_membership != 0) //check if it's not zero
		{
			ok = true; //return true
		}
		return ok;
	}

	Date Publication::checkoutDate() const
	{
		//Returns the date attribute
		return m_date;
	}

	bool Publication::operator==(const char* title) const
	{
		//Returns true if the argument title appears anywhere in the title of the publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		bool ok = false;
		if (strstr(m_title, title) != nullptr) 
		{
			ok = true; //return true
		}
		return ok;
	}

	Publication::operator const char* () const
	{
		//Returns the title attribute
		return m_title;
	}

	int Publication::getRef() const
	{
		//self explanatory
		//Returns the libRef attribute.
		return m_libRef;
	}

	bool Publication::conIO(std::ios& io) const
	{
		//Returns true if the address of the io object is the same as the address of either the cin object or the cout object.
		bool ok = false;
		if (&io == &std::cin || &io == &std::cout) //comparing adresses
		{
			ok = true; //return true
		}
		return ok;
	}

	std::ostream& Publication::write(std::ostream& os) const
	{
		//If the os argument is a console IO object (use conIO()), print shelfId, title,
		//membership and date attributes as the following format (title is left-justified padded with dots)
		//Otherwise: Print the type() and then libRef, shelfId, title, membership and date attributes in a tab - separated format.
		if (conIO(os)) //if true
		{
			int i;
			//need to print the shelf id then the title
			os << "| " << m_shelfId << " | ";
			//dot section
			if (strlen(m_title) > SDDS_TITLE_WIDTH)
			{
				for ( i = 0; i < SDDS_TITLE_WIDTH; i++)
				{
					os << m_title[i];
				}
			}
			else
			{
				os << m_title;
			}
			for ( i = 0; i < SDDS_TITLE_WIDTH - int(strlen(m_title)); i++)
			{
				os << ".";
			}
			os << " | "; //end of dots
			//shows membershio id, 0 will give N/A
			if (m_membership != 0) //any number below 5 digits
			{
				os << m_membership;
			}
			else //number is equal to 0
			{
				os << " N/A ";
			}
			os << " | "; //end of membership id
			//now the date
			os << m_date << " |"; //end for true
		}
		else //if false
		{
			//false format
			//Print the type() and then libRef, shelfId, title, membership and date attributes in a tab - separated format.
			os << type() << '\t' << m_libRef << "\t" << m_shelfId << '\t' << m_title << '\t';
			//shows membershio id, 0 will give N/A
			if (m_membership != 0) //any number below 5 digits
			{
				os << m_membership;
			}
			else //number is equal to 0
			{
				os << " N/A ";
			}
			os << '\t'; //end of membership id
			//last date
			os << m_date;
		}
		return os; //needs to return os.
	}

	std::istream& Publication::read(std::istream& is)
	{
		//Read all the values in local variables before setting the attributes to any values.
		char answer_title[SDDS_TITLE_MAX_LENGTH + 1] = { '\0' }, answer_sheldId[SDDS_SHELF_ID_LEN + 1] = { '\0' };
		int answer_membership = 0, answer_LibRef = -1;
		Date answer_date;

		//First, clear all the attributes by freeing the memory and setting everything to their default values.
		delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();

		//Then, if the istr argument is a console IO object (use conIO()) read the attributes as follows:
		if (conIO(is))
		{
			//shelf id input:
			//prompt: "Shelf No: "
			//read the shelf number up to its limit(see Lib.h).
			cout << "Shelf No: ";
			is.getline(answer_sheldId, SDDS_SHELF_ID_LEN + 1, '\n');
			//if the number is not exactly the length it is supposed to be, set the istr to a fail state manually.
			if (strlen(answer_sheldId) != SDDS_SHELF_ID_LEN)
			{
				is.setstate(ios::failbit);
			}

			//Title input
			//prompt: "Title: "
			//read the title
			cout << "Title: ";
			is.getline(answer_title, SDDS_TITLE_MAX_LENGTH + 1, '\n'); //increased the title length or the program would terminate, then i will filter later
			//date input
			//prompt : "Date: "
			//read the date
			cout << "Date: ";
			is >> answer_date;
		}
		else //Otherwise, assume reading begins with libRef attribute as if the type 'P' is not in the file.
		{
			//read the libRef number
			is >> answer_LibRef;
			//skip the tab
			is.ignore(1, '\t'); //it has to read one number
			//read the shelf number
			is >> answer_sheldId;
			//skip the tab
			is.ignore(SDDS_SHELF_ID_LEN + 1, '\t'); //proper size
			//read the title
			//skip the tab
			is.getline(answer_title, SDDS_TITLE_MAX_LENGTH + 1, '\t'); //char needs to be like that or my text goes wrong. //it will be filtered later for the console print
			//read the membership
			is >> answer_membership;
			//skip the tab
			is.ignore(1, '\t');
			//read the date
			is >> answer_date;
			//Either way if the date is in an invalid state set the istr to a fail state manually
		}
		if (!answer_date)
		{
			is.setstate(ios::failbit);
		}
		//After the process of reading is done if istr is in a valid state
		if (!is.fail()) //check if it's not invalid
		{
			//Dynamically store the title into the title attribute
			m_title = new char[strlen(answer_title) + 1];
			strcpy(m_title, answer_title);
			//copy the shelf id into the shelfId attribute
			strcpy(m_shelfId, answer_sheldId);
			//set the membership
			m_membership = answer_membership;
			//set the date
			m_date = answer_date;
			//set the libRef attribute
			m_libRef = answer_LibRef;
		}
		return is;
	}

	

	Publication::operator bool() const
	{
		//Returns true if neither of the title or shelfId attributes is null or empty. Otherwise, it will return false.
		bool ok = false; //start false until proved otherwise
		if (m_title != nullptr && m_shelfId[0] != '\0') //checking if both are not empty
		{
			ok = true; //return true
		}
		return ok; 
	}

}
