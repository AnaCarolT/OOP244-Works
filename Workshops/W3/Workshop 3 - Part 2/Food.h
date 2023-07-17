/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-03

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds {
	class Food
	{
		char m_foodName[31];
		int m_numCalories;
		int m_consumptionTime;
		void setName(const char* foodName);
	public:
		void setEmpty();
		void set(const char* foodName, int calories, int time);
		void display()const;
		bool isValid()const;
		int numCalories()const;
		int consumptionTime()const;
	};
}

#endif // !SDDS_FOOD_H
