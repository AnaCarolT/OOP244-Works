/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-08-07

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"

namespace sdds {


	//bool search - searches for a match with the key value
	//since we need to compare an array of a certain type indepedent if it's an int,char or double with the index. it was templated
	//the index can be anything and this affect the array since they are being compared. for example for cars we ssearched for "Tesla"(string) and students we searched for a gpa(double)
	//so that's why index is also a type2 so we can have more flexibility in the search
	//the object collection is a template because it's needs to be read by the copy constructor
	//numelem doesnt need a template because it's always going to be an int indepedent of the object
	template<typename type1, typename type2>
	bool search(Collection<type1>& templatedObj, type1 templatedArray[], int numElem, type2 index)
	{
		bool ok = false;
		int check = 0; //itineration number
		while (check < numElem) //loop for search
		{
			if (templatedArray[check] == index) //find the match
			{
				ok = true;
				//collection.h has an add function that can copy for us
				templatedObj.add(templatedArray[check]); //add the value inside the object
			}
			check++; //goes to the next element
		}
		return ok;
	}

	//void listArrayElements - it's like a display function
	//Here the template was only necessary so we could print different types in different objects or even in the same object
	//since it's only printing, the array can't be changed
	template<typename type>
	void listArrayElements(const char* title, const type templatedArray[], int numElem)
	{
		int currentElement = 0;
		std::cout << title << std::endl;
		//loop for printing
		while (currentElement < numElem)
		{
			//printing with the number on the front
			std::cout << currentElement + 1 << ": " << templatedArray[currentElement] << std::endl;
			currentElement++;
		}
	}
}
#endif // !SDDS_SEARCHNLIST_H