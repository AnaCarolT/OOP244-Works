/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-03

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;

namespace sdds
{
	void Food::setName(const char* foodName) 
	{
		strnCpy(m_foodName, foodName, 30); //copying
		m_foodName[30] = '\0'; //making sure it will not pass the limit
	}

	void Food::setEmpty() //clean
	{
		m_foodName[0] = '\0';
		m_numCalories = 0;
	}

	void Food::set(const char* foodName, int calories, int time)
	{
		if (foodName == nullptr || calories < 0) //cleaning so it makes validation easier
		{
			setEmpty();
		}
		else
		{
			setName(foodName);
			if (calories > 0) //avoiding wrong data if possible
			{
				m_numCalories = calories;
			}
			m_consumptionTime = time; 
		}
	}

	void Food::display()const 
	{
		if (isValid())
		{
			cout << "| ";
			cout.width(30); //adjust accordling to the header
			cout.fill('.'); //adding dots
			cout << left << m_foodName;
			cout << " | ";
			cout.width(4);
			cout.fill(' ');
			cout << fixed << right << m_numCalories << " | "; //making sure everything will stay in place since i'm working with numbers
			cout.width(10);
			cout.fill(' '); //since it's going to the right I need to fill with something or the dots will go everywhere
			switch (m_consumptionTime) //switch to make printing easier
			{
			case 1:
				cout << fixed << left << "Breakfast";
				break;
			case 2:
				cout << fixed << left << "Lunch";
				break;
			case 3:
				cout << fixed << left << "Dinner";
				break;
			case 4:
				cout << fixed << left << "Snack";
				break;
			}
			cout << " |" << endl;
		}
		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl; //do the width based on this base
		}
	}

	bool Food::isValid()const
	{
		return m_foodName[0] != '\0' && m_consumptionTime != '\0';
	}

	int Food::numCalories()const
	{
		return m_numCalories; //set it to use in  CalorieList
	}

	int Food::consumptionTime()const 
	{
		return m_consumptionTime; //set it to use in  CalorieList
	}
}