/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-17

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

* ctring.cpp and cstring.h was taken from my Workshop 1 Part 2 DYI.
  Since I did it in a past workshop.

///////////////////////////////////////////////////////////////////////////*/

#include "cstring.h"
namespace sdds {
    
    void strCpy(char* des, const char* src)
    {
        int i = 0;
        do
        {
            des[i] = src[i];
            i++;
        } while (src[i] != '\0');
        des[i] = '\0';
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i;
        for (i = 0; src[i] != '\0' && i < len; i++)
        {
            des[i] = src[i];
        }
        if (i < len)
        {
            des[i] = '\0';
        }
    }

}