/***********************************************************************
// Final Project Milestone 5
// Module: LibApp
// Filename: LibApp.h
// Version 1.0
// Author	Ana Tirolli
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ana Tirolli     2023-08-06      Adapt to MLS5
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
#include <fstream>
#include "LibApp.h"
#include "PublicationSelector.h"
#include "Book.h"

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
		//First print "Loading Data"
		cout << "Loading Data" << endl;
		//we need to load all the data from the file
		ifstream openFile(m_filename); //open file for reading
		//open the data file for reading and read all the publications in dynamic instances pointed by the PPA Array.
		char content = '\0';
		int i = 0;

		//used a similar logic like pubsel_tester
		//
		for ( i = 0; openFile;) //continue unti readings fail
		{
			//depending of the value of content, anew book or a new publication will be created
			openFile >> content; //store what was in the file to determine if it's a book or publication
			openFile.ignore(); //clean until whitespace

			if (openFile) //if the file open
			{
				//Do this by first reading a single character for the type of publication 
				switch (content)
				{
				case 'P':
					m_PPA[i] = new Publication;
					break;
				case 'B':
					m_PPA[i] = new Book;
					break;
				default: //safety measure I was using
					cout << "Something went wrong!";
					break;
				}

				if (m_PPA[i] && i < SDDS_LIBRARY_CAPACITY) //we need to check if ppa  is not empty and if we are not over the capacity
				{
					openFile >> *m_PPA[i]; //read the rest of the publication's data from the file
					//At the end set the LLRN to the reference number of the last publication read.
					m_LLTR = m_PPA[i]->getRef(); //update the last reference number
					//add one to the NOLP so it can increase the number of loaded publications
					m_NOLP++;
					//increment i to move to the next element
					i++;
				}
			}
		}
	}

	void LibApp::save()
	{
		// prints: "Saving Data"<NEWLINE>
		//First print "Saving Data"
		cout << "Saving Data" << endl;
		int i = 0;
		//pen the data file stream for overwriting.
		ofstream openFile(m_filename); //open file for writing
		//Go through the elements of PPA up to the N0LP.
		for (i = 0; i < m_NOLP; i++) //writing all the content based on the size acquired by the load
		{
			//nsert all elements into the ofstream object except those with 0 (zero)
			if (m_PPA[i]->getRef() != 0) //itinerating to get data from the curremt reference num
			{
				//insert the publication data into the ofstream object
				openFile << *m_PPA[i] << endl;
			}
		}
	}

	int LibApp::search(int state)
	{
		//create a publicationSelector object for handling the search matches
		PublicationSelector select("Select one of the following found matches:");
		//initialize local variables
		int idNum = 0, i = 0; //reference number and i for the itineration 
		char local_type = '\0'; //i need the info
		char local_title[SDDS_TITLE_MAX_LENGTH + 1]; //i need the info
		bool flag = false; //flag to abort

		//get the type of publication to search for from the user using type selection menu
		int choice = m_publicationmenu.run();
		if (choice == 1) //book
		{
			local_type = 'B';
		}
		else
		{
			if (choice == 2) //publication
			{
				local_type = 'P';
			}
			else
			{
				if (choice == 0) //exit
				{
					flag = true;
					cout << "Aborted!" << endl;
				}
			}
		}
		if (!flag) //didnt exit!
		{
			//get the input from the user about what title to search
			cout << "Publication Title: ";
			cin.getline(local_title, SDDS_TITLE_MAX_LENGTH + 1, '\n'); //extract input until null terminator
			//loop through all publications and check for matches
			for (i = 0; i < m_NOLP; i++)
			{
				//check each element
				//and if the publication (pointed by the PPA element) is not deleted (m_PPA[i]->getRef() != 0)
				//and the title contains the title the user entered (m_PPA[i]->type() == local_type && *m_PPA[i] == local_title)
				bool specifications = (m_PPA[i]->getRef() != 0 && m_PPA[i]->type() == local_type && *m_PPA[i] == local_title); //these apply for all
				//and type matches the selection of the use 
				if ((state == 1 && specifications)|| (state == 2 && m_PPA[i]->onLoan() && specifications) || (state == 3 && !m_PPA[i]->onLoan() && specifications))
				{
					// 1 - all the items
					// 2 - on loan items
					// 3 - available ones
					//insert it into the PublicationSelector object.
					select << m_PPA[i];
				}
			}
			//display like the pubsel_tester
			//display the search results based on the publicationselector object
			if (select)
			{
				//sort the search results from publication selector
				select.sort();
				//run the selector menu to get the user's choice
				idNum = select.run();
				//Display the publication details if a valid selection is made and if the user dont exit
				if (idNum != 0 ? cout << *getPub(idNum) << endl : cout << "Aborted!" << endl);

			}
			else
			{
				//in case of no matches
				cout << "No matches found!" << endl;
			}
		}
		//return the ref num of the selected publication
		return idNum;
	}

	void LibApp::returnPub() //messages in case a publication is returned
	{
		//get current day for calculations
		Date currentDay;
		//print the message
		cout << "Return publication to the library" << endl;
		//Calls the search() method with state 2 for checkout items on loan
		int state = search(2);
		//check if a valid publication is found for return
		if (state != 0)
		{
			//ask confirmation from the user to return the publication
			if (confirm("Return Publication?"))
			{
				//calculate the number of days for the loan
				int overdue = currentDay - getPub(state)->checkoutDate();
				//If the publication is more than 15 days on loan, a 50 cents per day penalty will be calculated for the number of days exceeding the 15 days.
				//if it's overdue
				if (overdue > SDDS_MAX_LOAN_DAYS)
				{
					int daysOnLoan = overdue - SDDS_MAX_LOAN_DAYS;
					//fix the value for printing
					cout.setf(ios::fixed);
					// dot two decimals
					cout.precision(2);

					//print the message with the value they need to pay and how many days it has been
					cout << "Please pay $" << double(daysOnLoan) * 0.5 << " penalty for being " << daysOnLoan << " days late!" << endl;
				}
				//set the membership number of the publication to 0 (zero)
				getPub(state)->set(0);
				//sets m_changed to true;
				m_changed = true;
				// prints "Publication returned"<NEWLINE>
				cout << "Publication returned" << endl;
			}
			else //anything else
			{
				cout << "Aborted!" << endl;
			}
		}
	}

	void LibApp::newPublication() //"adding" new publication
	{
		//If the NOLP is equal to the SDDS_LIBRARY_CAPACITY, print: "Library is at its maximum capacity!" and exit.
		if (m_NOLP == SDDS_LIBRARY_CAPACITY) //we need to check if it's not over the limit
		{
			cout << "Library is at its maximum capacity!" << endl;
		}
		else
		{
			//print: "Adding new publication to the library"
			cout << "Adding new publication to the library" << endl;
			Publication* pub{};
			//get the publication type from the user.
			int choice = m_publicationmenu.run();
			if (choice == 1) //book
			{
				pub = new Book;
			}
			else
			{
				if (choice == 2) //publication
				{
					pub = new Publication;
				}
				else
				{
					if (choice == 0) //none
					{
						cout << "Aborted!" << endl;
						pub = nullptr;
					}
				}
			}
			//calls the confirm method with "Add this publication to library?"
			//now we need to receive input
			if (pub)
			{
				cin >> *pub;
				//Read the instantiated object from the cin object.
				if (cin)
				{
					//If the cin is ok, then confirm that the user wants to add the publication to the library using this prompt
					if (confirm("Add this publication to the library?"))//if confirm returns true
					{
						if ((*pub)) //if the publication object is valid
						{
							//Add the publication object's address to the end of the PPA
							m_PPA[m_NOLP] = pub;
							//Add one to the LLRN and set the library reference number to the value
							m_PPA[m_NOLP]->setRef(++m_LLTR);
							//and add one to the NOLP.
							m_NOLP++; //need to be added since there is a new pub
							//set the "changed" flag to true
							m_changed = true;
							//print: "Publication added"
							cout << "Publication added" << endl;
						}
						else
						{
							//If the publication object is not valid print : "Failed to add publication!" and delete the allocated memory.
							cout << "Failed to add publication!" << endl;
							delete pub; //avoid memory leak
						}
					}
					else
					{
						//If the user did not confirm, print "Aborted!" and exit.
						cout << "Aborted!" << endl;
						delete pub; //avoid memory leak
					}
				}
				else
				{
					//If the cin fails, flush the keyboard, print "Aborted!" and exit.
					delete pub; //avoid memory leak
					//flush keyboard
					cin.ignore(1000, '\n');
					cout << "Aborted!" << endl;
				}
			}
		}
	}

	void LibApp::removePublication() //"removing" publication
	{
		int state;
		//prints "Removing publication from library"+newline
		cout << "Removing publication from the library" << endl;
		//Search all the publications(1)
		state = search(1);
		//If the user selects a publication
		if (state != 0)
		{
			//calls the confirm method with "Remove this publication from the library?"
			//if confirm returns true
			if (confirm("Remove this publication from the library?"))
			{
				//confirms to remove the publication using the prompt
				//Set the library reference of the selected publication to 0 (zero)
				getPub(state)->setRef(0);
				//set the "changed" flag to true
				m_changed = true;
				//print: "Publication removed"
				cout << "Publication removed" << endl;
			}
			else //in case anything else happens
			{
				//safety measure
				cout << "Aborted!" << endl;
			}
		}
	}

	void LibApp::checkOutPub() //"Check out" the publication
	{
		int state, temp_memb = 0; //local variables to get data
		//print: "Checkout publication from the library"
		cout << "Checkout publication from the library" << endl;
		//calls the search method
		//Search in available publications only (3)
		state = search(3);
		//If the user selects a publication
		if (state != 0)
		{
			//calls the confirm method with Check out publication?"
			//if confirm returns true
			if (confirm("Check out publication?"))
			{
				//confirms to checkout
				//ask for the number
				cout << "Enter Membership number: ";
				//Read a 5 digit number from the console
				while (cin >> temp_memb && (temp_memb < 1 || temp_memb > 99999)) //read until it's right
				{
					cout << "Invalid membership number, try again: "; //print question again
				}
				//set the membership number of the selected publication the integer value.
				getPub(state)->set(temp_memb);
				//set the changed flag to true
				m_changed = true;
				//print: "Publication checked out"
				cout << "Publication checked out" << endl;
			}
			else
			{
				//in case anything happens.
				//it's just a safety measure
				cout << "Aborted!" << endl;
			}
		}
	}

	Publication* LibApp::getPub(int libRef) const
	{
		int i = 0;
		Publication* indexResult = NULL;
		//loop through the PPa to find the publication with the specific ref number
		for ( i = 0; i < m_NOLP && !indexResult; i++)
		{
			//if the reference matches
			if (m_PPA[i]->getRef() == libRef)
			{
				//set to point to the publication
				indexResult = m_PPA[i];
			}
		}
		return indexResult; //return the ref num of a Publication
	}

	LibApp::LibApp(const char* fileName) : m_NOLP(0), m_LLTR(0), m_mainMenu("Seneca Library Application"), m_exitmenu("Changes have been made to the data, what would you like to do?"), m_publicationmenu("Choose the type of publication:")
	{
		m_changed = false;

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
		//we need ti populate the publication menu
		m_publicationmenu.addItem("Book");
		m_publicationmenu.addItem("Publication");
		//I need to add the filename
		strcpy(m_filename, fileName);
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
		//this will only appear if m_changed stayed false
		//m_changed being false should terminate
		cout << endl; //adding a new line so the output is correct
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

	LibApp::~LibApp()
	{
		//avoid memory leak
		int i;
		//loop through all the ppas
		for (i = 0; i < m_NOLP; i++) //avoid memory leak on everything
		{
			delete m_PPA[i];
			m_PPA[i] = nullptr;
		}
	}
}
