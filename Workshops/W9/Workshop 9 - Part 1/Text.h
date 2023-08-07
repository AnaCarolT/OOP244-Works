/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-31

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>
#include "cstring.h"

namespace sdds {
   class Text {

       //Hold the name of the file dynamically
      char* m_filename ;

      //Holds the content of the text file dynamically.
      char* m_content ;


      int getFileLength()const; // Code provided in Text.cpp

   protected:

      const char& operator[](int index)const;

   public:

      Text(const char* filename=nullptr);

      // implement rule of three here

      //copy constructor
      Text(const Text& text);

      //copy assignment
      Text& operator=(const Text& text);

      //destructor
      ~Text();


      void read();


      virtual void write(std::ostream& os)const;
   };

   // prototype of insertion overload into ostream goes here
   std::ostream& operator<<(std::ostream& leftOperand, const Text& rightOperand);
}
#endif // !SDDS_TEXT_H__

