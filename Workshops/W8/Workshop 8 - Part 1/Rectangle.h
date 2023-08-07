/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-24

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"

namespace sdds {

	//The Rectangle class inherits the LblShape class to create a frame with a label inside.
	class Rectangle : public LblShape { //

		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* label,int width, int height);
		//!!!! This class has no destructor implemented.
		void draw(std::ostream& os) const;
		void getSpecs(std::istream& is);
	};
}
#endif // !RECTANGLE_H
