/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef CSTRING_H
#include <iostream>
using namespace std;

namespace sdds
{

    void strCpy(char* des, const char* src);
    void strnCpy(char* des, const char* src, int len);
    int strCmp(const char* s1, const char* s2);
    int strnCmp(const char* s1, const char* s2, int len);
    int strLen(const char* s);
    const char* strStr(const char* str1, const char* str2);
    void strCat(char* des, const char* src);
}


#endif // !CSTRING_H