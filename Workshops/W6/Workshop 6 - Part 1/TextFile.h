/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>

namespace sdds {

    //Starting Line class

   class Line { 
       //Reminder it's fully private
       //v holds the address of the dynamically allocated Cstring (to hold a line of the text file)
      char* m_value{ nullptr };
      //v Returns the address held in the m_value attribute.
      operator const char* ()const;
      //v Initializes the m_value attribute to nullptr.
      Line() {}
      //v Dynamically allocates memory in m_value and copies the Cstring pointed by lineContent into it.
      Line& operator=(const char* lineContent);
      //v destructor
      ~Line(); //Makes sure all the allocated memory is freed.
      friend class TextFile; //already added as a friend

      //- TO DO -
      // copy and copy assignment prevention goes here
      Line(const Line&) = delete; //copy constructor blocked
      Line& operator=(const Line&) = delete; //copy assignment blocked

   };

   //Starting TextFile class

   class TextFile {

   private:
       //v A pointer to hold the dynamic array of Lines. This attribute should be initialized to nullptr
      Line* m_textLines;
      //v A pointer to hold the dynamic Cstring holding the name of the file. This attribute should be initialized to nullptr
      char* m_filename;
      //v An unsigned integer to be set to the number of lines in the file.
      unsigned m_noOfLines;
      //v The page size is the number of lines that should be displayed on the screen before the display is paused.
      //v After these lines are displayed, the user must hit enter for the next page to appear.
      unsigned m_pageSize;
      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();

   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile&);
      TextFile& operator=(const TextFile& textFile);
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };

   //Outside of both classes
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__
