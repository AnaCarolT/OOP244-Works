/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-05-18
///////////////////////////////////////////////////////////////////////////*/

#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include "ShoppingRec.h"
#include "File.h"
using namespace std;

namespace sdds {

	const int MAX_NO_OF_RECS = 15;

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();

}


#endif // !SHOPPINGLIST_H