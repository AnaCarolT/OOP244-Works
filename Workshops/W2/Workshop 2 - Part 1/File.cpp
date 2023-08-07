/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-05-25
///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds 
{
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   //TODO: read functions go here    
   bool read(char* employeeName)
   {
       bool result = false;
       if (fscanf(fptr, "%[^\n]\n", employeeName) == 1)
       {
           result = true;
       }
       return result;
   }
   bool read(int& employeeNumber)
   {
       bool result = false;
       if (fscanf(fptr, "%d, ", &employeeNumber) == 1)
       {
           result = true;
       }
       return result;
   }
   bool read(double& employeeIncome)
   {
       bool result = false;
       if (fscanf(fptr, "%lf, ", &employeeIncome) == 1)
       {
           result = true;
       }
       return result;
   }
}