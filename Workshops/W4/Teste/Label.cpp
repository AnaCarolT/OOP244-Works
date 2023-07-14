// Label.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <iostream>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "Label.h"
using namespace std;

namespace sdds
{
    Label::Label()
    {
        // Creates an empty label and
        // defaults the frame to "+-+|+-+|"
        m_content = new char[70];
        strCpy(m_content, "");
        strCpy(m_frame, "+-+|+-+|");
    }

    Label::Label(const char* frameArg)
    {
        // Creates an empty label and 
        // sets the frame to the frameArg argument.
        m_content = new char[70];
        strCpy(m_content, "");
        strCpy(m_frame, frameArg);
    }

    Label::Label(const char* frameArg, const char* content)
    {
        // Creates a Label with the frame set to frameArg and 
        // the content of the Label set to the corresponding argument. 
        // Note that you must keep the content dynamically even though 
        // it should never be more than 70 characters.
        if (frameArg)
        {
            // strcpy frameArg to frame by checking provided or else copy default 
            strCpy(m_frame, frameArg);
        }

        if (content)
        {
            // do DMA for content find the size then DMA and then strcpy
            m_content = new char[strLen(content)];
            strCpy(m_content, content);
        }
    }

    // deconstructors 
    void Label::readLabel()
    {
        // Reads the label from console up to 70 characters
        // and stores it in the Label 
        fgets(m_content, 70, stdin);
        // trim the newline from user input
        m_content[strLen(m_content) - 1] = '\0';
    }

    ostream& Label::printLabel() const
    {
        // Prints the label by drawing the frame around the content 
        // and shown in the Execution sample. 
        // Note that no newline is printed after the last line and 
        // cout is returned at the end.
        int w = strLen(m_content) + 2;
        cout << m_frame[0] << string(w, m_frame[1]) << m_frame[2] << endl;
        cout << m_frame[7] << string(w, ' ') << m_frame[3] << endl;
        cout << m_frame[7] << " " << m_content << " " << m_frame[3] << endl;
        cout << m_frame[7] << string(w, ' ') << m_frame[3] << endl;
        cout << m_frame[6] << string(w, m_frame[5]) << m_frame[4];
        return cout;
    }
}