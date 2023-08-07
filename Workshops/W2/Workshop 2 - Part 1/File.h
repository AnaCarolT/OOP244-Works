/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-05-25
///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds 
{
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
	bool read(char* employeeName);
	bool read(int& employeeNumber);
	bool read(double& employeeIncome);
}
#endif // !SDDS_FILE_H_
