/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-24

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LblShape.h"

using namespace std;

namespace sdds {

	const char* LblShape::label() const //make it easier to use label
	{
		//Add a query called label that returns the unmodifiable value of m_label member variable.
		return m_label;
	}

	LblShape::LblShape() //first constructor
	{
		//Sets the label pointer to null.
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label) //second constructor
	{
		if (label != nullptr)
		{
			//Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable
			m_label = new char[strlen(label) + 1];
			//Then copies the Cstring argument to the newly allocated memory.
			strcpy(m_label, label);
		}
		else
		{
			m_label = nullptr; //just for safety
		}
	}

	LblShape::~LblShape() //destructor
	{
		//Deletes the memory pointed by m_label member variable.
		delete[] m_label;
	}

	void LblShape::getSpecs(std::istream& is) //Reads a comma-delimited Cstring form istream
	{
		char str[500]; //I couldn't make it work with a string so i decided to use char
		if (m_label) //if label is not empty
		{
			delete[] m_label;
			m_label = nullptr;
		}
		//extract and ignore the comma
		is.get(str, 500, ','); //pick the new label
		is.ignore(); //clean the buffer including the null terminator
		m_label = new char[strlen(str) + 1]; //allocate memory for the new label
		strcpy(m_label, str); //copy the new label
	}
}