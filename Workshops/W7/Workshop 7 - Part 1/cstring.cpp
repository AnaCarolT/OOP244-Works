/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6 Part 1
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 10 July 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

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

    int strLen(const char* s)
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