/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

* ctring.cpp and cstring.h was taken from my Workshop 1 Part 2 DYI.
  Since I did it in a past workshop.

///////////////////////////////////////////////////////////////////////////*/

#include "cstring.h"
namespace sdds {
    void strCpy(char* des, const char* src)
    {
        while (*src != '\0')
        {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0';
    }
    //it was necessary to change or it wouldn't read the text
    unsigned strLen(const char* s)
    {
        int i;
        int len = 0;
        for (i = 0; s[i] != '\0'; i++)
        {
            len++;
        }
        return len;
    }
    void strCat(char* des, const char* src)
    {
        while (*des != '\0')
        {
            des++;
        }
        while (*src != '\0')
        {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0';
    }
}