/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-03

I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;

namespace sdds 
{
	int CalorieList::totalnumCalories()const 
	{
		int sumCalories = 0; //setting to 0 to be safe
		int i = 0;
		for ( i = 0; i < m_foodAdded; i++)
		{
			sumCalories += m_food[i].numCalories(); //I need to use numCalories() from file.h
		}
		return sumCalories;
	}

	void CalorieList::Title()const 
	{
		cout << "+----------------------------------------------------+" << endl; //count the - to adjust width, take 2 off because I added manually
		if (isValid())
		{
			cout << "|  "; //space manually added just to be sure is not gonna touch the border
			cout.width(50);
			cout << left << "Daily Calorie Consumption"; //need to be on the left
			cout << "|" << endl; //new line
		}
		else
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl; //header in case of invalid
		}
		cout << "+--------------------------------+------+------------+" << endl; //this will always appear
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer()const 
	{
		cout << "+--------------------------------+------+------------+" << endl; //adjust width according to this base
		if (isValid())
		{
			cout << "|    Total Calories for today: "; //dont forget to count this spaces used out of width
			cout.width(8);
			cout << fixed << right << totalnumCalories() << " |            |" << endl; //this will never change

		}
		else
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl; //If invalid
		}
		cout << "+----------------------------------------------------+" << endl; //no change, footer
	}

	void CalorieList::setEmpty() //emptying to avoid errors
	{
		m_food = nullptr;
		m_noOfFood = 0;
		m_foodAdded = 0;
	}

	bool CalorieList::isValid()const //second validation so the display can adjust
	{
		int ok; //I feel safer when I adjust ok manually, optional tho
		ok = true;
		int i;
		if (m_food == nullptr)
		{
			ok = false;
			return ok;
		}
		else
		{
			for (i = 0; i < m_noOfFood; i++)
			{
				if (!m_food[i].isValid()) //calling the validation in food.h
				{
					ok = false;
					return ok;
				}
			}
		}
		return ok;
	}

	void CalorieList::init(int noOfFoods) //remember "size"
	{
		int i = 0;
		if (noOfFoods > 0) //true
		{
			m_noOfFood = noOfFoods;
			m_foodAdded = 0;
			m_food = new Food[m_noOfFood];
			for (i = 0; i < m_noOfFood; i++)
			{
				m_food[i].setEmpty();
			}
		}
		else //false
		{
			setEmpty();
		}
	}

	bool CalorieList::add(const char* food_name, int numCalories, int time) //adding item information
	{
		if (m_foodAdded < m_noOfFood)
		{
			m_food[m_foodAdded].set(food_name, numCalories, time); //calling from file.h
			m_foodAdded++; //counter
			return true;
		}
		else
		{
			return false;
		}
	}

	void CalorieList::display()const  //making the items appear
	{
		int i = 0;
		Title();
		for (i = 0; i < m_noOfFood; i++)
		{
			m_food[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() 
	{
		delete[] m_food;
		m_food = nullptr;
	}
}