/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "LabelMaker.h"
using namespace std;

namespace sdds 
{
	void LabelMaker::setToDefault() //first constructor
	{
		m_labels = nullptr; //safe state
	}

	LabelMaker::LabelMaker(int numLabels) //second constructor
	{
		m_numLabels = numLabels; //setting num of labels
		m_labels = new Label[m_numLabels];
	}

	LabelMaker::~LabelMaker() //destructor
	{
		delete[] m_labels; //deallocate
	}

	void LabelMaker::readLabels() 
	{
		int i;
		cout << "Enter " << m_numLabels << " labels:" << endl;
		for ( i = 0; i < m_numLabels; i++) //using for loop because it will recognize the number of labels
		{
			cout << "Enter label number " << i + 1 << endl;
			m_labels[i].readLabel();
		}
	}
	void LabelMaker::printLabels()  //It just needs to print the labels
	{
		int i;
		for ( i = 0; i < m_numLabels; i++)
		{
			m_labels[i].printLabel();
			cout << endl;
		}
	}
}
