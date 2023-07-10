/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-17

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "Mark.h"

namespace sdds {

	void Mark::setEmpty() //In case it is out of the conditions
	{
		m_number = -1; //put it as invalid until proved otherwise
	}

	bool Mark::validValues() const
	{
		int ok;
		ok = false;
		if (m_number >= 0 && m_number <= 100)  //inside the proper parameters
		{
			return true; //ok
		}
		return ok; //not okay
	}

	Mark::Mark() //set value to a safe state in case no value is inserted
	{
		m_number = 0; //safe state
	}

	Mark::Mark(int number) //triggers when an int is inserted
	{
		if (number >= 0 && number <= 100) //checking if the value getting in is valid
		{
			m_number = number; //Copying it to m_number
		}
		else
		{
			setEmpty(); //set as invalid
		}
	}

	Mark::operator int() const //check when a new value is assigned after passing by the constructor
	{
		if (validValues()) //checking the value "copied" (m_number)
		{
			return m_number; //return the value
		}
		else
		{
			return 0; //if invalid it returns 0
		}
	}

	Mark::operator double() const //GPA pattern? (1 to 5 instead of 0 to 100)
	{
		if (validValues()) //checking the value "copied" (m_number)
		{
			if (m_number >= 80) //checking which double it needs to be substitute to
			{
				return 4.0;
			}
			else 
			{
				if (m_number >= 70)
				{
					return 3.0;
				}
				else
				{
					if (m_number >= 60)
					{
						return 2.0;
					}
					else
					{
						if (m_number >= 50)
						{
							return 1.0;
						}
						else
						{
							return 0; //return 0 if it's below 50
						}
					}
				}
			}
		}
		return 0; //return 0 if it's invalid
	}

	Mark::operator char() const
	{
		if (validValues()) //checking the value "copied" (m_number)
		{
			if (m_number >= 80)
			{
				return 'A';
			}
			else
			{
				if (m_number >= 70)
				{
					return 'B';
				}
				else
				{
					if (m_number >= 60)
					{
						return 'C';
					}
					else
					{
						if (m_number >= 50)
						{
							return 'D';
						}
						else
						{
							return 'F'; //below 50
						}
					}
				}
			}
		}
		return 'X'; //invalid
	}

	Mark& Mark::operator+=(int number)
	{
		if (validValues()) //checking m_number
		{
			m_number += number; //adding the values
		}
		return *this; //return m_number
	}

	Mark& Mark::operator=(int number)
	{
		m_number = number;  //adding number's value to m_number so I can use validValues and it will change either way if it's not valid
		if (validValues()) //checks m_number but I should be checking number, since it's what i'm receiving
		{
			//if it's valid, does nothing.
		}
		else
		{
			setEmpty(); //invalid turns into -1.
		}
		return *this; //return m_number
	}

	int operator+=(int& number, const Mark& mark) //we will receive the value and the whole class
	{
		if (mark.validValues()) //using the public member
		{
			number += (int)mark; //it only adds a value to val if the number entered is valid, because val constantly changes value as you keep adding.
			//mark have an operator int, so we need to call it so mark can be added
		}
		return number; //result
	}

}