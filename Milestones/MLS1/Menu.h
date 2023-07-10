/***********************************************************************
// Final Project Milestone 1
// Module: Menu
// Filename: Menu.h
// Version 1.0
// Author	Ana Tirolli
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
// -----------------------------------------------------------
//
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

namespace sdds {

	const unsigned int MAX_MENU_ITEMS = 20; //unsigned int

	class MenuItem {

		char* m_menuItem; //item name
		MenuItem(); //constructor with no argument
		MenuItem(const char* menuItem); //constructor with one argument
		MenuItem(const MenuItem&) = delete; //copy constructor blocked
		MenuItem& operator=(const MenuItem&) = delete; //copy assignment blocked
		~MenuItem(); //destructor
		operator bool() const; //bool
		operator const char* () const; //return address
		void display(std::ostream& os) const; //display menu
		friend class Menu; //set menu as friend, giving permission for menu to access MenuItem that is fully private
	};

	class Menu {

		MenuItem m_title;
		MenuItem* m_listItems[MAX_MENU_ITEMS];
		int m_IDItems;
		void setToDefault(); //to avoid repeting code

	public:
		Menu(); //constructor with no arguments
		Menu(const char* title); //constructor with one argument
		Menu(const Menu&) = delete; //copy constructor blocked
		Menu& operator=(const Menu&) = delete; //copy assignment blocked, wont let me copy directly
		~Menu(); //destructor
		void addItem(const char* menuItem); //a function to add the items
		void header() const; //helps with the title
		void body() const; //helps with the body
		std::ostream& display(std::ostream& os) const; //split menu, since menuItem is fully private
		int run() const; //validation for the input
		operator bool() const; //checks menuItem
		operator int() const; 
		operator unsigned int() const;
		int operator~() const;
		const char* operator[](int i) const; //return address of C string
		Menu& operator<<(const char* menuItem);
	};

	std::ostream& operator<<(std::ostream& os, const Menu& menu);

}
#endif // SDDS_MENU_H__