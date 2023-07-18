/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-03

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"

namespace sdds 
{
	class CalorieList
	{
		Food* m_food;
		int m_noOfFood;
		int m_foodAdded;
		int totalnumCalories()const;
		void Title()const;
		void footer()const;
		void setEmpty();
		bool isValid()const;
	public:
		void init(int noOfFoods);
		bool add(const char* food_name, int numCalories, int time);
		void display()const;
		void deallocate();
	};
}

#endif // !SDDS_CALORIELIST_H
