/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-01
///////////////////////////////////////////////////////////////////////////*/

#include "cstring.h"
namespace sdds {
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