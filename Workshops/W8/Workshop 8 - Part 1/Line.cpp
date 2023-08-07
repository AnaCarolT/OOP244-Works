/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-24

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "Line.h"

using namespace std;

namespace sdds {

	//Sets the m_length member variable to zero, and invokes the default constructor of the base class.
	Line::Line():LblShape()
	{
		m_length = 0;
	}

	//Passes the Cstring to the constructor of the base class
	Line::Line(const char* label, int length):LblShape(label)
	{
		//sets the m_length member variable to the value of the second argument.
		m_length = length;
	}

	void Line::draw(std::ostream& os) const //This function overrides the draw function of the base class.
	{
		int i;
		//If the m_length member variable is greater than zero and the label() is not null
		if (m_length > 0 && label() != nullptr)
		{
			// this function will first print the label()
			os << label() << endl;
			//It keeps printing the '=' (assignment character) to the value of the m_length member variable
			for ( i = 0; i < m_length; i++)
			{
				os << '=';
			}
		}
	}

	void Line::getSpecs(std::istream& is)
	{
		//Reads comma-separated specs of the Line from istream.
		//This function overrides the getSpecs function of the base class as follows.
		LblShape::getSpecs(is);
		//reaad m_length
		is >> m_length;
		//it will ignore The rest of the characters up to and including the newline character '\n'.
		is.ignore();
	}
}