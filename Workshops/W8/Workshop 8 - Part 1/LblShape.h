/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-24

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef LBLSHAPE_H
#define LBLSHAPE_H

#define _CRT_SECURE_NO_WARNINGS
#include "Shape.h"

namespace sdds {

	class LblShape : public Shape {
		//Add a character pointer member variable called m_label
		char* m_label = NULL;

	protected:
		const char* label() const;

	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		//The copy constructor and assignment operator are deleted to prevent copying or assignment of instances of this class.
		LblShape(const LblShape&) = delete; //copy constructor
		LblShape& operator=(const LblShape&) = delete; //copy assignment
		void getSpecs(std::istream& is);
	};
}
#endif // !LBLSHAPE_H

