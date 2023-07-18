/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Mark.h"

using namespace std;
using namespace sdds;
int main() {
   Mark m, n(25), k(200), p(-10); //constructors triggers
   cout << "int ............" << endl; 
   cout << int(m) << endl; 
   cout << int(n) << endl;
   cout << int(k) << endl;
   cout << int(p) << endl;
   cout << "+= ............." << endl;
   cout << int(m += 20) << endl; //pass through 2 operators
   cout << int(n += 20) << endl;
   cout << int(k += 20) << endl;
   cout << int(n += 60) << endl;
   cout << "= .............." << endl;
   cout << int(m = 80) << endl;  //constructor then operator
   cout << int(n = 120) << endl;
   cout << int(k = 70) << endl;
   cout << "double ........." << endl;
   m = 50; n = 80; k = 120; //Call the "=" the constructor
   cout << double(m) << endl; //check what to return
   cout << double(n) << endl;
   cout << double(k) << endl;
   cout << "char ..........." << endl; 
   cout << char(m) << endl; //check what to return
   cout << char(n) << endl;
   cout << char(k) << endl;
   cout << "int += Mark ..." << endl; //adding an int with a class
   int val = 60;
   cout << (val += n) << endl;
   cout << (val += k) << endl;
   return 0;
}