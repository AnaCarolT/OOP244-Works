/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-05-27
///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	int numOfPopRecords;
	PopRecord* pop;

    bool load(PopRecord& records)
    {

        bool ok = false;
        char postalcode[128];

        if (read(postalcode) && read(records.population)) //If successful
        {
            records.postalCode = new char[strLen(postalcode) + 1];
            strCpy(records.postalCode, postalcode);
            ok = true;
        }
        return ok;
    }

    bool load(const char filename[])
    {
        bool ok = false;
        int i = 0;

        if (openFile(DATAFILE))
        {
            numOfPopRecords = noOfRecords();
            pop = new PopRecord[numOfPopRecords];
            do
            {
                load(pop[i]);
                i++;

            } while (i < numOfPopRecords);

            if (i != numOfPopRecords)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
            }
            else
            {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    void display(PopRecord& records)
    {
        cout << records.postalCode << ":  " << records.population << endl;
    }
    void display()
    {
        int i, j, k;
        int sumPop = 0;
        PopRecord popDisplay;

        cout << "Postal Code: population" << endl; //Header
        cout << "-------------------------" << endl;
        for ( j = numOfPopRecords - 1; j > 0; j--) //Needed to be sorted by population
        {
            for ( k = 0; k < j; k++)
            {
                if (pop[k].population > pop[k + 1].population)
                {
                    popDisplay = pop[k];
                    pop[k] = pop[k + 1];
                    pop[k + 1] = popDisplay;
                }
            }
        }
        for (i = 0; i < numOfPopRecords; i++) //Employees itineration
        {
            cout << i + 1 << "- ";
            display(pop[i]);
            sumPop += pop[i].population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: "<< sumPop << endl;
    }
    void deallocateMemory()
    {
        int i;
        for (i = 0; i < numOfPopRecords; i++)
        {
            delete[] pop[i].postalCode;
        }
        delete[] pop;
        pop = nullptr;
        numOfPopRecords = 0;
    }
}