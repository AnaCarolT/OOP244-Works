/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include "cstring.h"
#include "Label.h"
using namespace std;

namespace sdds
{
	void Label::setToDefault()
	{
		m_border = nullptr; //safe state
		m_inside = nullptr;
		delete[] m_border;
		m_border = new char[9]; //prepare to receive data
	}

	Label::Label()  //first constructor
	{
		setToDefault();
		strCpy(m_border, "+-+|+-+|"); //default frame
		delete[] m_inside;
		m_inside = new char[70]; //70 is the limit
		strCpy(m_inside, ""); //empty label
	}

	Label::Label(const char* format) //second constructor
	{
		setToDefault();
		strCpy(m_border, format); //adjust frame to format
		delete[] m_inside;
		m_inside = new char[70]; 
		strCpy(m_inside, ""); //empty label
	}

	Label::Label(const char* format, const char* inside) //third constructor
	{
		setToDefault();
		if (format) //check if the default state was applied
		{
			strCpy(m_border, format);
		}

		if (inside) //check if the default state was appliedto avoid errors in the code
		{
			delete[] m_inside;
			m_inside = new char[strLen(inside) + 1];
			strCpy(m_inside, inside);
		}
		//without the validation, the code will work but prompt to abort
	}

	Label::~Label() //desconstructor
	{
		delete[] m_border;
		delete[] m_inside;
	}

	void Label::readLabel()
	{
		//I need to limit it to 70 characters
		cout << "> ";
		char userInput[71]; //For a string we add +1 for the null terminator
		int len;
		cin.getline(userInput, 71); //pulling the use input until 70
		userInput[70] = '\0'; //making sure it will stop at 70
		len = strLen(userInput); //getting length
		delete[] m_inside; //ssuper important to deallocate memory here
		m_inside = new char[len + 1]; //+1 to the fit the null terminator
		strCpy(m_inside, userInput); //copy
	}

	std::ostream& Label::printLabel() const
	{
		int lenInside;
		lenInside = strLen(m_inside); //we will use the inside so it's easier to make the shape

		if (lenInside > 0) //Labels need to be created when there is content or the right frame
		{

			cout << m_border[0]; //calling each part that was set by default
			cout.fill(m_border[1]);
			cout.width(lenInside + 2); //size of the sentence plus the empty spaces from both sides
			cout << "" << m_border[2] << endl;

			cout << m_border[7]; //I put more couts so I could visualize it better
			cout.fill(' '); //filling spaces
			cout.width(lenInside + 2); //telling when fill should stop
			cout << "" << m_border[3] << endl;

			cout << m_border[7] << " ";
			cout << m_inside;
			cout << " " << m_border[3] << endl;

			cout << m_border[7];
			cout.fill(' ');
			cout.width(lenInside + 2);
			cout << "" << m_border[3] << endl;

			cout << m_border[6];
			cout.fill(m_border[5]);
			cout.width(lenInside + 2);
			cout << "" << m_border[4];
		}	
		return cout; //It said it needs to return cout
	}
}