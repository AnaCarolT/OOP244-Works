/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-08

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

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

    int strCmp(const char* s1, const char* s2)
    {
        int i;
        for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        {
            if (s1[i] != s2[i])
            {
                return s1[i] - s2[i];
            }
        }
        return s1[i] - s2[i];
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

}