/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#include <iostream>

namespace sdds
{
	class Label
	{
		char* m_border;
		char* m_inside;
		void setToDefault(); //put things in a default/safe state
	public:
		Label();
		Label(const char* format);
		Label(const char* format, const char* inside);
		~Label();
		void readLabel();
		std::ostream& printLabel() const;
	};
}
#endif // !SDDS_LABEL_H