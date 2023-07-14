/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-01
///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;

namespace sdds {

    double Bill::totalTax()const 
    {
        double sumTaxes = 0.0;
        int i = 0;
        do
        {
            sumTaxes += m_items[i].tax();
            i++;
        } while (i < m_itemsAdded);

        return sumTaxes;
    }

    double Bill::totalPrice()const
    {
        double sumPrices = 0.0;
        int i = 0;
        do
        {
            sumPrices += m_items[i].price();
            i++;
        } while (i < m_itemsAdded);

        return sumPrices;
    }

    void Bill::Title()const 
    {
        cout << "+--------------------------------------+" << endl;
        if (isValid())
        {
            cout << "| ";
            cout.width(36);
            cout << left << m_title;
            cout << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer()const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.precision(2);
            cout << fixed << right << totalTax() << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10);
            cout.precision(2);
            cout << fixed << right << totalPrice() << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.precision(2);
            cout << fixed << right << totalTax() + totalPrice() << " |" << endl;

        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty() 
    {
        m_title[0] = '\0'; 
        m_items = nullptr;
    }

    bool Bill::isValid()const 
    {
        bool ok;
        ok = true;
        int i;
        if (m_title[0] == '\0' || m_items == nullptr)
        {
            ok = false;
        }
        else
        {
            for ( i = 0; i < m_noOfItems; i++)
            {
                if (!m_items[i].isValid())
                {
                    ok = false;
                    return ok;
                }
            }
        }

        return ok;
    }

    void Bill::init(const char* title, int noOfItems) 
    {
        int i = 0;
        if (title != nullptr || noOfItems > 0)
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_title[36] = '\0';
            m_items = new Item[m_noOfItems];
            for ( i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
        else
        {
            setEmpty();
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed) 
    {
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        else
        {
            return false;
        }
    }

    void Bill::display()const
    {
        int i = 0;
        Title();
        for ( i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }
}