/***********************************************************************
// Final Project Milestone 1
// Module: LibApp
// Filename: LibApp.h
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

#include <iostream>
#include "LibApp.h"

using namespace std;
namespace sdds {
	//confirm if 1 was chosen
	bool LibApp::confirm(const char* message)
	{
		//Instantiate a Menu in this function and initialize it with the message argument.
		Menu menu(message);
		//Then add only a "yes" as a single menu item to the Menu.
		menu.addItem("Yes");
		//run the menu
		return menu.run() == 1; //returning anything besides 1 is false
	}

	void LibApp::load()
	{
		// prints: "Loading Data"<NEWLINE>
		cout << "Loading Data" << endl; 
	}

	void LibApp::save()
	{
		// prints: "Saving Data"<NEWLINE>
		cout << "Saving Data" << endl;
	}

	void LibApp::search()
	{
		// prints: "Searching for publication"<NEWLINE>
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub() //messages in case a publication is returned
	{
		//Calls the search() method.
		search();
		//prints "Returning publication"<NEWLINE>
		cout << "Returning publication" << endl;
		// prints "Publication returned"<NEWLINE>
		cout << "Publication returned" << endl;
		//sets m_changed to true;
		m_changed = true;
	}

	void LibApp::newPublication() //"adding" new publication
	{
		bool validation;
		//prints "Adding new publication to library"+newline
		cout << "Adding new publication to library" << endl;
		//calls the confirm method with "Add this publication to library?"
		validation = confirm("Add this publication to library?");
		//if confrim returns true
		if (validation == true)
		{
			//it will set m_changed to true and prints "Publication added" + newline
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}

	void LibApp::removePublication() //"removing" publication
	{
		bool validation;
		//prints "Removing publication from library"+newline
		cout << "Removing publication from library" << endl;
		//calls the search method
		search();
		//calls the confirm method with "Remove this publication from the library?"
		validation = confirm("Remove this publication from the library?");
		//if confirm returns true
		if (validation == true)
		{
			//it will set m_changed to true and prints "Publication removed" + newline
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}

	void LibApp::checkOutPub() //"Check out" the publication
	{
		bool validation;
		//calls the search method
		search();
		//calls the confirm method with Check out publication?"
		validation = confirm("Check out publication?");
		//if confirm returns true
		if (validation == true)
		{
			//it will set m_changed to true and prints "Publication checked out" + newline
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}

	LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitmenu("Changes have been made to the data, what would you like to do?")
	{
		//default values were set directly in the function so it always initializes that way

		//we need to populate the main menu
		//the function additem can add any item to the menu
		m_mainMenu.addItem("Add New Publication");
		m_mainMenu.addItem("Remove Publication");
		m_mainMenu.addItem("Checkout publication from library");
		m_mainMenu.addItem("Return publication to library");
		//we need to populate the exit menu
		m_exitmenu.addItem("Save changes and exit");
		m_exitmenu.addItem("Cancel and go back to the main menu");
		load(); //print the load message
	}

	void LibApp::run() //it's the stucture of the main menu
	{
		//m_changed starts as false
		//tester is also calling the menu 
		int answer = -1; //not using zero because it gives trouble in the loop, so i'm assumin the user will not enter a negative number (-1).
		int saveOrNot = -1; //not using zero because of loop
		bool flag = false; //setting flag as a bool
		while (flag == false) //while flag is false continue
		{
			//gets the user input in the main menu
			answer = m_mainMenu.run();
			switch (answer)
			{
			//this option should stop the loop when necessary
			case 0:

				//if there were changes in "content"
				if (m_changed == true)
				{
					//If the value is true, the m_exitMenu is used by calling its run method.
					saveOrNot = m_exitmenu.run();
					if (saveOrNot == 1)
					{
						//save
						save();
						//stop loop
						flag = true;
					}
					else
					{

						if (saveOrNot == 2)
						{
							//cancelling
							cout << endl;
						}
						else
						{
							//exit without saving
							//flag in this case will be turned to true if the person wanna discard the changes so it will stop the menu
							flag = confirm("This will discard all the changes are you sure?");
						}
					}
				}
				else
				{
					//if no changes, stop main menu, terminate
					flag = true;
				}
				break;
			//any of this options will continue loop
			case 1: //new publibication
				newPublication(); //changes m_changed
				cout << endl;
				break;
			case 2: //remove publication
				removePublication(); //changes m_changed
				cout << endl;
				break;
			case 3: //check out publication
				checkOutPub(); //changes m_changed
				cout << endl;
				break;
			case 4: //return publication
				returnPub(); //changes m_changed
				cout << endl;
				break;
			//default in case anything else is entered
			default:
				break;
			}
		}
		//Tester made it confusing since sometimes you can terminate but the main menu is being called again
		//this will only appear if m_changed stayed false
		//m_changed being false should terminate
		cout << endl; //adding a new line so the output is correct
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
}
