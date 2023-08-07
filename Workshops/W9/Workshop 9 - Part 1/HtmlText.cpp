/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-31

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include "HtmlText.h"

using namespace std;

namespace sdds {

	HtmlText::HtmlText(const char* filename, const char* title):Text(filename), m_title(nullptr) //constructor with 2 arguments
	{
		//filename and title are =nullptr in the function
		if (title != nullptr && title[0] != '\0') //checking if it's not empty
		{
			m_title = new char[strLen(title) + 1]; //allocating space
			strCpy(m_title, title); //copying
		}
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title; //deleting m_title to avoid memory leak
		m_title = nullptr;
	}

	HtmlText::HtmlText(const HtmlText& htmltext):Text(htmltext) //copy constructor
	{
		//also picking informtion from the copy constructor from the parent
		m_title = nullptr; //setting m_title to nullptr
		*this = htmltext; //copying htmltext into *this
	}

	HtmlText& HtmlText::operator=(const HtmlText& htmltext) //copy assignment
	{
		if (this != &htmltext) //checking if they are not equal
		{
			Text::operator=(htmltext); //invoking the operator= from the parent
			delete[] m_title; //setting m_title in a safe state, step 1
			m_title = nullptr;// step 2
			m_title = new char[strLen(htmltext.m_title) + 1]; //allocating space
			strCpy(m_title, htmltext.m_title);//copying after putting the right amount of space
		}
		return *this;
	}
	void HtmlText::write(std::ostream& os) const //void don't return anything
	{
		//create a boolean variable and set it to false to keep track of the occurance of multiple spaces(let's call it MS for Multiple Spaces)
		bool MS = false;
		//variable for the loop
		int i = 0;
		//insert "<html><head><title>"
		os << "<html><head><title>";
		//if m_title is not null, insert the title
		if (m_title != nullptr)
		{
			os << m_title; //insert title
		}
		else
		{
			//otherwise insert "No Title"
			os << "No Title";
		}
		//insert "</title></head>\n<body>\n"
		os << "</title></head>\n<body>\n";
		if (m_title != nullptr)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}
		//loop through all the elements of the m_content (using the protected index operator) and convert the characters as follows
		while ((*this)[i] != '\0') //it will go as long as it is not empty
		{
			if ((*this)[i] == '<')
			{
				// In case the value is '<'
				//insert "&lt;" and set the MS to false
				os << "&lt;";
				MS = false;
			}
			else
			{
				if ((*this)[i] == '>')
				{
					//In case the value is '>'
					//insert "&gt;" and set the MS to false
					os << "&gt;";
					MS = false;
				}
				else
				{
					if ((*this)[i] == '\n')
					{
						//In case the value is newline '\n'
						//insert "<br />\n" and set the MS to false
						os << "<br />\n";
						MS = false;
					}
					else
					{
						if ((*this)[i] == ' ')
						{
							//In case the value is a space
							//if MS is true insert "&nbsp;"
							//otherwise set MS to true and then insert a space(' ')
							if (MS)
							{
								os << "&nbsp;";
							}
							else
							{
								os << ' ';
								MS = true;
							}
						}
						else
						{
							// In all other cases
							//set the MS to false and insert the current value, unchanged.
							os << (*this)[i];
							MS = false;
						}
					}
				}
			}
			i++; //the index need to move for the other ones to be checked
		}
		//at the end insert "</body>\n</html>" to end the html page.
		os << "</body>\n</html>";
	}
}