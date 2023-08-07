/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-24

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef LINE_H
#define LINE_H

#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"

namespace sdds {

	class Line : public LblShape { //Line inherits the LblShape class to create a horizontal line with a label.

		int m_length;
	public:
		Line();
		//Receives a Cstring and a value for the length of the line
		Line(const char* label, int length);
		//!!! This class has no destructor implemented
		void draw(std::ostream& os) const;
		void getSpecs(std::istream& is);
	};
}
#endif // !LINE_H
