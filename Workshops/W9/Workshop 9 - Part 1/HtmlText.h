/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-31

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__

#include "Text.h" //need to list the parent

namespace sdds {

   class HtmlText :  public Text {

       //Holds the title of the HTML conversion dynamically
      char* m_title;

   public:

       //constructor that was in the file
      HtmlText(const char* filename=nullptr, const char* title = nullptr);

      //the rule of three is implemented here

      //destructor
      ~HtmlText();
      
      //copy constructor
      HtmlText(const HtmlText& htmltext);
      
      //copy assignment
      HtmlText& operator=(const HtmlText& htmltext);
      
      //This override will convert the text file to a simple HTML file
      void write(std::ostream& os)const;
   };
   //it can use the ostream form the parent 
}
#endif // !SDDS_HTMLTEXT_H__
