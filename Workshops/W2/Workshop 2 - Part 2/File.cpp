/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-05-27
///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
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
   //READ
   bool read(char* postalcode)
   {
       bool result = false;
       if (fscanf(fptr, "%[^,],", postalcode) == 1)
       {
           result = true;
       }
       return result;
   }
   bool read(int& population) 
   {
       bool result = false;
       if (fscanf(fptr, "%d\n", &population) == 1)
       {
           result = true;
       }
       return result;
   }
}