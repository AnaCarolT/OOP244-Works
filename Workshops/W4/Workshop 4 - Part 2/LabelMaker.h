/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef LABELMAKER_H
#define LABELMAKER_H

#include <iostream>
#include "Label.h"

namespace sdds 
{
	class LabelMaker
	{
		Label* m_labels;
		int m_numLabels = 0;
		void setToDefault();
	public:
		LabelMaker(int numLabels);
		~LabelMaker();
		void readLabels();
		void printLabels();
	};
}


#endif // !LABELMAKER_H


