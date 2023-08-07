/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-05-25
///////////////////////////////////////////////////////////////////////////*/

#include "cstring.h"

namespace sdds 
{
    void strCpy(char* des, const char* src) 
    {
        int i = 0;
        do
        {
            *des = *src;
            i++;
        } while (src[i] != '\0');
        des[i] = '\0';
    }
    void strnCpy(char* des, const char* src, int len) 
    {
        int i;
        for ( i = 0; src[i] != '\0' && i < len; i++)
        {
            des[i] = src[i];
        }
        if (i < len)
        {
            des[i] = '\0';
        }
    }
    int strCmp(const char* s1, const char* s2)
    {
        int i;
        for ( i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        {
            if (s1[i] != s2[i])
            {
                return s1[i] - s2[i];
            }
        }
        return s1[i] - s2[i];
    }
    int strnCmp(const char* s1, const char* s2, int len) 
    {
        int i;
        for (i = 0; s1[i] != '\0' && s2[i] != '\0' && i < len; i++)
        {
            if (s1[i] != s2[i])
            {
                return s1[i] - s2[i];
            }
        }
        if (i == len)
        {
            return 0;
        }
        return s1[i] - s2[i];
    }
    int strLen(const char* s) 
    {
        int i;
        int len = 0;
        for ( i = 0; s[i] != '\0'; i++)
        {
            len++;
        }
        return len;
    }
    const char* strStr(const char* str1, const char* str2) 
    {
        const char* result;
        result = (*str2 == '\0') ? str1 : nullptr;
        do
        {
            const char* first = str1;
            const char* second = str2;
            bool found = true;

            for (; *second != '\0'; first++, second++)
            {
                if (*first != *second)
                {
                    found = false;
                }
            }
            if (found)
            {
                return str1;
            }
            str1++;
        } while (*str1 != '\0');

        return result;
    }
    void strCat(char* des, const char* src)
    {
        if (*des != '\0')
        {
            do
            {
                des++;
            } while (*des != '\0');
            
        }
        if (*src != '\0')
        {
            do
            {
                *des++ = *src++;
            } while (*des != '\0');
        }
        *des = '\0';
    }
}