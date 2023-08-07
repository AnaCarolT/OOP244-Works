/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-24

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

namespace sdds {

	class Shape {
	public:
		virtual ~Shape() {}; //put it on default mode
		//Returns void and receives a reference to ostream as an argument. This pure virtual function can not modify the current object.
		virtual void draw(std::ostream& os) const = 0; //no definition
		//Returns void and receives a reference to istream as an argument.
		virtual void getSpecs(std::istream& is) = 0; //no definition
	};
	std::ostream& operator<<(std::ostream& os, const Shape& shape);
	std::istream& operator>>(std::istream& is, Shape& shape);
}

#endif // SHAPE_H

