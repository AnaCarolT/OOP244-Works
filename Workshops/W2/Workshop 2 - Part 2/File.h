/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-05-27
///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* postalcode);
   bool read(int& population);
}
#endif // !SDDS_FILE_H_
