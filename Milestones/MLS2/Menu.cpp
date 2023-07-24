/***********************************************************************
// Final Project Milestone 2
// Module: Menu
// Filename: Menu.cpp
// Version 1.0
// Author	Ana Tirolli
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//Ana Tirolli      2023-07-21      Changes for MLS2
//
// -----------------------------------------------------------
//
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
#include "Menu.h"

namespace sdds {

	//STARTING MENUITEM

	MenuItem::MenuItem() {

		m_menuItem = nullptr; //set to no pointer
	}

	MenuItem::MenuItem(const char* menuItem) {

		if (menuItem != nullptr && menuItem[0] != '\0') //checking if there is a pointer before copying
		{
			m_menuItem = new char[strlen(menuItem) + 1]; //adjusting to be the size of the name + null terminator
			strcpy(m_menuItem, menuItem); //no limit of char mentioned so strcpy
		}
		else
		{
			m_menuItem = nullptr; //setting to no pointer since it's a safe state
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_menuItem; //to avoid memory leak
	}

	MenuItem::operator bool() const
	{
		bool ok = false;
		if (m_menuItem != nullptr) //checking if it's not empty
		{
			ok = true;
		}
		return ok;
	}

	MenuItem::operator const char* () const
	{
		return m_menuItem; //return address of cstring
	}

	void MenuItem::display(std::ostream& os) const
	{
		if (m_menuItem != nullptr) //if empty, menuitem is not printed
		{
			os << m_menuItem;
		}
	}

	//STARTING MENU

	void Menu::setToDefault()
	{
		m_IDItems = 0; //no items in the menu
		int i;
		//initialize array of pointers to nullptr
		for (i = 0; i < int(MAX_MENU_ITEMS); i++) //problems compiliting if you don't turn the unsigned int into an int
		{
			m_listItems[i] = nullptr; //loop through items
		}
	}

	Menu::Menu()
	{
		setToDefault(); //safe state
	}

	Menu::Menu(const char* title)
	{
		setToDefault(); //safe state
		int titleLength = 0;
		if (title != nullptr && title[0] != '\0') //checking if title is not empty
		{
			//due to delete we can't allocate memory directly, m_title = new char[strlen(title + 1)] doesn't work;
			titleLength = int(strlen(title) + 1); //getting the length adding one for null character
			//it kept complaining about possible loss of data because of strlen so I changed it to an int
			m_title.m_menuItem = new char[titleLength]; //accessing menuItem due to the friend relationship and allocating memory
			strncpy(m_title.m_menuItem, title, titleLength);  //passing the item name through
			m_title.m_menuItem[titleLength - 1] = '\0'; //making sure it's the right size
		}
		else
		{
			m_title.m_menuItem = nullptr; //in case it's empty, we set to a safe state
		}
	}

	Menu::~Menu()
	{
		int i;
		for (i = 0; i < m_IDItems; i++) //detructor to avoid memory leak
		{
			delete m_listItems[i]; //deleting
			m_listItems[i] = nullptr; //setting to no pointer
		}
	}

	void Menu::addItem(const char* menuItem)
	{
		if (m_IDItems < int(MAX_MENU_ITEMS)) //add items as long as it respects the limit
		{
			m_listItems[m_IDItems] = new MenuItem(menuItem); //allocate memory
			m_IDItems++; //goes to the next empty spot
		}
	}

	void Menu::header() const //to print the title since sometimes is not necessary
	{
		if (m_title != nullptr && m_title[0] != '\0') //checking if it's not empty
		{
			cout << m_title.m_menuItem; //print
		}
	}

	void Menu::body() const //print only the body of the menu
	{
		int i = 0;
		header();
		if (m_title != nullptr && m_title[0] != '\0') //checking if it's not empty to go together with the title printed before
		{
			cout << endl; //remove colon
		}
		if (m_IDItems >= 0 && m_IDItems < int(MAX_MENU_ITEMS)) //making sure it's a valid number
		{
			for (i = 0; i < m_IDItems; i++) //checking items to print
			{
				cout << setw(2) << i + 1 << "- " << m_listItems[i]->m_menuItem << endl; //setting it up to print nicely
			}
			cout << " 0- Exit" << endl << "> "; //Exit always need to appear at the end.
		}
	}

	std::ostream& Menu::display(std::ostream& os) const
	{
		header(); //prints the top if there is a top, it'a not going to call the body when it's empty
		return os;
	}

	int Menu::run() const
	{
		body(); //prints the body, run calls the body because the person need the options before answering
		int answer; //store answer
		int flag = 0; //setting flag so it can stop when the right answer is found

		while (flag == 0)
		{
			cin >> answer;
			if (cin.fail()) //using fail() to check if it's not an integer first
			{
				cin.clear(); //clear so it can continues even if there is an error, without this it will get stuck in the cleaning buffer
				//without cleaning the buffer it keeps going in an infinite loop
				while (cin.get() != '\n'); //cleaning input buffer, if clear is not used, it will get stuck
				cout << "Invalid Selection, try again: ";
			}
			else
			{
				if (answer < 0 || answer > m_IDItems) //improper answer if it's an int
				{
					cout << "Invalid Selection, try again: "; //printing question
				}
				else
				{
					flag = 1; //break
				}
				while (cin.get() != '\n'); // cleaning input buffer
				//just to be extra safe, it's not really necessary in this case since it's going to be overwritten.
			}
		}

		return answer; //returning proper answer
	}

	Menu::operator bool() const
	{
		bool ok = false;
		if (m_IDItems > 0 && m_IDItems < int(MAX_MENU_ITEMS)) //checking if quantity of items is correct
		{
			ok = true;
		}
		return ok;
	}

	Menu::operator int() const
	{
		return run(); //should work like run so I called run
	}

	Menu::operator unsigned int() const
	{
		return m_IDItems; //should return the items number
	}

	int Menu::operator~() const
	{
		return run(); //should work like run so I called run
	}

	const char* Menu::operator[](int i) const //return a c string 
	{
		//i for index of item number
		if (i >= 0 && i < m_IDItems) //checking if it is in the range of the current items
		{
			return m_listItems[i]->operator const char* (); //Access menuItem through the friend privilege
			//use the operator const char* so it can be converted to a c string address
			//doing this based on the returning of the function
			//return it to menu
		}
		return nullptr; //if out of range, there is no pointer
	}

	Menu& Menu::operator<<(const char* menuItem)
	{
		addItem(menuItem); //adding items that are valid
		return *this; //returning the valid items
	}

	//OUTSIDE OF BOTH CLASSES
	std::ostream& operator<<(std::ostream& os, const Menu& menu)
	{
		return menu.display(os); //return the object menu directly to the output stream
		//so you it's possible to show the menu content without itinerating
	}
}