/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-01
///////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

    void Item::setName(const char* name) 
    {
        strnCpy(m_itemName, name, 20);
        m_itemName[20] = '\0';
    }

    void Item::setEmpty() 
    {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }

    void Item::set(const char* name, double price, bool taxed) 
    {
        if (name == nullptr || price < 0.0)
        {
            setEmpty();
        }
        else
        {
            setName(name);
            if (price > 0.0)
            {
                m_price = price;
            }
            m_taxed = taxed;
        }
    }

    void Item::display()const 
    {
        if (isValid()) 
        {
            cout << "| ";
            cout.width(20);
            cout.fill('.');
            cout << left << m_itemName;
            cout << " | ";
            cout.width(7);
            cout.precision(2);
            cout.fill(' ');
            cout << fixed << right << m_price << " | ";
            if (m_taxed)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No ";
            }
            cout << " |" << endl;
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }    
    }

    bool Item::isValid()const 
    {
        if (m_itemName[0] != '\0')
        {
            return true;
        }
        return false;
    }

    double Item::price()const 
    {

        return m_price;
    }

    double Item::tax()const 
    {
        const double tax = 0.13;
        if (m_taxed)
        {
            return m_price * tax;
        }
        else
        {
            return 0.0;
        }
    }

}