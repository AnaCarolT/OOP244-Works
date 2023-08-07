/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-24

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "Shape.h"

using namespace std;

namespace sdds {

	//Overload the insertion and extraction operators (using draw and getSpecs functions)
	ostream& operator<<(ostream& os, const Shape& shape) //write
	{
		shape.draw(os);
		return os;
	}

	istream& operator>>(istream& is, Shape& shape) //read
	{
		shape.getSpecs(is);
		return is;
	}
}