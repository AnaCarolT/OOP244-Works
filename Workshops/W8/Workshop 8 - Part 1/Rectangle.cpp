/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-24

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include <cstring>
#include "Rectangle.h"

using namespace std;

namespace sdds {

    //invoke the default constructor of the base class.
	Rectangle::Rectangle():LblShape() 
	{
        //Sets the width and height member variables to zero.
		m_width = 0;
		m_height = 0;
	}

    // Passes the Cstring to the constructor of the base class
    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
        //sets the m_width and m_height member variables to the corresponding values received from the argument list.
        m_width = width;
        m_height = height;
        //if the m_height is less than 3 or m_width is less the length of the label() + 2
        if (m_height < 3 || m_width < int(strlen(label) + 2)) {
            //it will set the Rectangle to an empty state.
            m_width = 0;
            m_height = 0;
        }
    }

    void Rectangle::draw(std::ostream& os) const {
        int i, j;

        if (m_width > 0 && m_height > 0)
        {
            //First line/Top line:
            //prints '+', then prints the '-' character(m_width - 2) times and then prints '+' and goes to newline.
            os << "+";
            for ( i = 0; i < m_width - 2; i++)
            {
                os << "-";
            }
            os << "+" << endl;

            //Second line/label:
            //prints '|', then in(m_width - 2) spaces it prints the label() left justified and then prints '|' and goes to new line.
            os << "|" << label();
            //tried using os.width and it was giving me overflow
            for ( i = 0; i < m_width - int(strlen(label())) - 2; i++) //filling with empty spaces after printing the label
            {
                //printing manually
                os << " ";
            }
            os << "|" << endl;

            // In next(m_height - 3) lines /middle body:
            //prints '|', (m_width - 2) spaces then prints '|' and goes to new line.
            for ( i = 0; i < m_height - 3; i++) ///start
            {
                //does the parts that only need spaces
                os << "|";
                for ( j = 0; j < m_width - 2; j++)
                {
                    //goes based on the size of the square besides the borders
                    os << " ";
                }
                os << "|" << endl;
            } //end

            //Last line: exactly like first line.
            //Bottom line
            os << "+";
            for ( i = 0; i < m_width - 2; i++)
            {
                //prints "-" except for the borders
                os << "-";
            }
            os << "+";
        }
    }

    void Rectangle::getSpecs(std::istream& is) {
        //it will call the getSpecs function of the base class
        LblShape::getSpecs(is);
        //then it will read two comma-separated values from istream for m_width and m_length
        is >> m_width; //reading width
        is.ignore(); //cleaning buffer
        is >> m_height; //reading height
        is.ignore(150, '\n'); //will ignore until it finds the null terminator
    }

}