/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-05-27
///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#define DATAFILE "PCpopulations.csv"

namespace sdds {

	struct PopRecord
	{
		char* postalCode;
		int population;
	};

    // loads the records
    bool load(PopRecord& records);
    // records into the array
    bool load(const char filename[]);
    // displays a record record on the screen:
    void display(PopRecord& records);
    // first sorts the data then displays all
    void display();
    // first will deallocate all the names in the records element 
    void deallocateMemory();

}
#endif // SDDS_POPULATION_H_