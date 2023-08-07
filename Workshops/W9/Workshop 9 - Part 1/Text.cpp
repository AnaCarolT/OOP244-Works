/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-31

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS //cstring is annoying
#include <fstream> //it was already in the file (it's for reading/writing files)
#include "Text.h"

using namespace std;

namespace sdds {

    //code provided
    //it returns the length (size) of the text file on the disk. It returns zero if either the file does not exist or the content is empty.
   int Text::getFileLength() const {

      int len = 0; //this will be the counter

      ifstream fin(m_filename); //open file

      while (fin) { //this will read the length of the text file
         fin.get();
         len += !!fin;
      }//the counter will resturn 0 if does not exist or it's empty

      return len; //return any changes in len if it's not hcanged,, it's 0
   }

   //protected function meaning it can be accessed by the derived class (read only)
   const char& Text::operator[](int index) const
   {
       //The behaviour of the operator is not defined if the index goes out of bounds
       //Should I not let it flip? does it get a weird result?
       //This instruction was not clear
       return m_content[index]; //return m_content and their index
   }

   //beginning public
   Text::Text(const char* filename):m_filename(nullptr), m_content(nullptr) //constructor with one argument
   {
       //address of filename
       //m_filename start as nullptr
       //m_content start as nullptr
       if (filename != nullptr) //if it's not null
       {
           m_filename = new char[strLen(filename) + 1]; //allocate space for filename
           strCpy(m_filename, filename); //copy
           read(); //This will start m_content correctly with no failure
           //using this to simplify the code
       }
   }

   Text::Text(const Text& text):m_filename(nullptr), m_content(nullptr) //constructor with one argument
   {
       //holding Text
       //m_filename start as nullptr
       //m_content start as nullptr
       *this = text; //transfer everything from text
   }

   Text& Text::operator=(const Text& text) //copy constructor
   {
       //if text is different we copy everything in
       if (this != &text)
       {
           delete[] m_filename; //delete everything first
           delete[] m_content;
           m_filename = nullptr; //then make sure there is no pointer
           m_content = nullptr;
           m_filename = new char[strLen(text.m_filename) + 1]; //allocating space
           strCpy(m_filename, text.m_filename); //copy when it's safe
           read(); //this will start m_content as we desire
       }
       return *this; //operator= always return *this
   }

   Text::~Text() //destructor
   {
       //avoid memory leak
       delete[] m_filename; //delete
       delete[] m_content;
       m_filename = nullptr; //make sure there is no pointer
       m_content = nullptr;
   }

   void Text::read() //it will be exclusive on reading m_content
   {
       delete[] m_content; //delete
       m_content = nullptr; //make sure there is no pointer
       char content = '\0'; //this will hold my content temporaly
       int fileLength = 0, i = 0; //i need to know the length

       ifstream openFile(m_filename); //remember this open, this close, this is the complete package
       //First, read will the current content of the file and then allocates memory to the size of the file on the disk + 1 (for the null byte).
       fileLength = getFileLength();
       m_content = new char[fileLength + 1];
       //now we have the length and have allocated space
       if (!openFile) //check if it opened properly
       {
           cout << "File couldn't be opened"; //just a guide so I can check if I did some mistake.
       }
       else
       {
           //Then it will read the contents of the file character by character into the newly allocated memory
           while (openFile.get(content))
           {
               m_content[i] = content;
               i++;
           }
           //terminates it with a null byte at the end
           m_content[i] = '\0';
           //cout << Succesful!!
       }
   }

   void Text::write(std::ostream& os) const
   {
       if (m_content != nullptr) //check if it's not empty/no pointer
       {
           os << m_content; //print constent
       }
       //void don't return
   }

   //outside of the class
   std::ostream& operator<<(std::ostream& leftOperand, const Text& rightOperand)
   {
       //Overload the insertion operator for a Text object into ostream
       rightOperand.write(leftOperand); //base write //call write
       return leftOperand;
   }

}