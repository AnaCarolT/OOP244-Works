/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-17

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef MARK_H
#define MARK_H

namespace sdds {

	class Mark
	{
		int m_number;
		void setEmpty();
	public:
		Mark();
		Mark(int number);
		operator int() const;
		operator double() const;
		operator char() const;
		Mark& operator+=(int number);
		Mark& operator=(int number);
		bool validValues() const; //putting it public so the operators can call it even outside the class
	};

	int operator+=(int& number, const Mark& mark);
}

#endif // !MARK_H

