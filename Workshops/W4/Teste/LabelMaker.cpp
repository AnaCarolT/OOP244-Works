// LabelMaker.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <iostream>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "LabelMaker.h"
using namespace std;

namespace sdds
{
    LabelMaker::LabelMaker(int noOfLabels)
    {
        // creates a dynamic array of Labels to the size of noOfLabels
        m_noOfLabels = noOfLabels;
        m_labels = new Label[m_noOfLabels];
    }

    void LabelMaker::readLabels()
    {
        // Gets the contents of the Labels as 
        // demonstrated in the Execution sample
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for (int i = 0; i < m_noOfLabels; i++)
        {
            cout << "Enter label number " << (i + 1) << endl;
            cout << "> ";
            m_labels[i].readLabel();
        }
    }

    void LabelMaker::printLabels()
    {
        // Prints the Labels as demonstrated in the Execution sample
        for (int i = 0; i < m_noOfLabels; i++)
        {
            m_labels[i].printLabel() << endl;
        }
    }

    LabelMaker::~LabelMaker()
    {
        // Deallocates the memory when LabelMaker goes out of scope.
        delete[] m_labels;
    }
}