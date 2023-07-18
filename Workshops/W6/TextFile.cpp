/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-10

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "TextFile.h"
#include "cstring.h"
#define TEXT_SIZE 256 //setting as a macro since i worked with chars


using namespace std;

namespace sdds {


    //Starting Line class
   Line::operator const char* () const 
   {

       //const char* means it returns an addres value
      return (const char*)m_value;
   }

   Line& Line::operator=(const char* lineContent) 
   {
      delete[] m_value;

      //needs validation, not recommended to just put the values directly
      if (lineContent)
      {
          m_value = new char[strLen(lineContent) + 1]; //include the null terminator
          strCpy(m_value, lineContent);
      }
      else
      {
          m_value = nullptr;
      }

      return *this;
   }

   Line::~Line() 
   {
      delete[] m_value;
   }
   //--end of Line class--


   //Starting TextFile class
   //--Starting Private Memebers--

   void TextFile::setFilename(const char* fname, bool isCopy)
   {
       delete[] m_filename;
       //isCopy confirms if it's a copy or not
       if (isCopy) {
           m_filename = new char[strLen(fname) + 3]; //Save space for the C_ and the null terminator
           strCpy(m_filename, "C_");
           strCat(m_filename, fname);
       }
       else
       {
           m_filename = new char[strLen(fname) + 1]; //save space only for the null terminator
           strCpy(m_filename, fname);
       }
   }

   void TextFile::setNoOfLines()
   {
       int counter = 0; //Counts the number of lines in the file
       char wholeLine[TEXT_SIZE];
       ifstream File; //Creates a local ifstream object to open the file with the name held in m_filename.
       File.open(m_filename); //opening file
       if (File.is_open()) //in case the file open/true
       {
           while (File.getline(wholeLine, sizeof(wholeLine))) //each line in the file is read and we need to make sure it will not get more length than necessary
           {
               //In the end, it will increase m_noOfLines by one
               counter++;
           }
       }
       File.close(); //closing file

       if (counter == 0) //If the number of lines is zero, it will delete the m_filename and set it to nullptr.
       {
           delete[] m_filename; //setting everything to empty safe state
           m_filename = nullptr;
           m_noOfLines = 0;
       }
       else 
       {
           m_noOfLines = counter; //total num of lines
       }
   }

   void TextFile::loadText()
   {       
       delete[] m_textLines;
       ifstream File; //setting to be able to call the file
       int i; //for loop

       if (m_filename == nullptr) //If it has no pointer, it can just skip
       {
           return;
       }
       m_textLines = new Line[m_noOfLines]; //alocatting the space necessary to be used
       File.open(m_filename); //opening the file
       if (File.is_open()) //If the file opens
       {
           char wholeLine[TEXT_SIZE]; //Assuming that's the maximum a line can reach

           //sizeof work simirlarly to strlen but it doesn't get the null terminator so it's better
           //if it's less than the number of lines and getline is detecting data it will continue
           for (i = 0; i < int(m_noOfLines) && File.getline(wholeLine, sizeof(wholeLine)); i++)
           {
               m_textLines[i] = wholeLine; //adding one by one
           }
       }
       File.close(); //close the file
   }

   void TextFile::saveAs(const char* fileName) const
   {
       if (m_filename == nullptr) //If it has no pointer, it can just skip
       {
           return;
       }
       //Now for "printing" so it's necessary the ofstream
       ofstream Save;
       int i;
       Save.open(fileName); //opening file
       if (Save.is_open()) //if it doesn't fail opening
       {
           //It will keep going as long as less than the number of lines
           for ( i = 0; i < int(m_noOfLines); i++) //reminder that since m_noOfLines is unsigned if I don't put as an int it will give me errors
           {
               Save << m_textLines[i] << '\n'; //writing on the file
           }
       }
       Save.close(); //closing file 
   }

   void TextFile::setEmpty() //setting everything to a safe state
   {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   //Starting public Members
   TextFile::TextFile(unsigned pageSize) //"constructor with one argument"
   {
       m_pageSize = pageSize; //making sure the value passed in well received
       this->m_filename = nullptr; //setting to a safe state but since Line is blocked we need to use this
       this->m_textLines = nullptr; //safe state
       this->m_noOfLines = 0; //safe state
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) //constructor with 2 arguments"
   {
       m_pageSize = pageSize; //making sure the value passed in well received
       this->m_filename = nullptr; //use this since Line is blocked //safe state
       this->m_textLines = nullptr; //safe state
       this->m_noOfLines = 0; //safe state
       if (filename != nullptr) //if filename has a pointer, we need to pull data
       {
           setFilename(filename); //gathering the name
           setNoOfLines(); //getting num of lines
           loadText(); //read lines
       }
   }

   TextFile::TextFile(const TextFile& textFile) //"constructor with TextFile as an argument
   {
       m_pageSize = textFile.m_pageSize; //making sure the value passed in well received
       this->m_filename = nullptr; //use this since Line is blocked //safe state
       this->m_textLines = nullptr; //safe state
       this->m_noOfLines = 0; //safe state
       setFilename(textFile.m_filename, true); //true tell that it's a copy
       setNoOfLines(); //finding num of lines
       loadText(); //read lines
   }

   TextFile& TextFile::operator=(const TextFile& textFile)
   {
       if (this == &textFile) //checking if the objects are identical
       {
           return *this; //if yes return reference of the current object
       }
       delete[] this->m_textLines; //safe state //this since Line is blocked
       m_textLines = nullptr; //safe state
       textFile.saveAs(m_filename); //saving the currently textFile
       setNoOfLines(); //num of lines
       loadText(); //read the text
       return *this; //return reference of the current object
   }

   TextFile::~TextFile()
   {
       this->setEmpty(); //deleting everything
   }

   std::ostream& TextFile::view(std::ostream& ostr) const
   {
       if (!*this) //using bool to check if the object is in an invalid state
       {
           return ostr; //if yes, return ostr with no action
       }

       int nameLength = 0;
       int index = 0;
       int i = 0;
       ostr << m_filename << endl; //print file name
       if (m_filename != nullptr) //if filename is not nullptr we search for the length
       {
           nameLength = int(strLen(m_filename) );
       }

       while (i < nameLength) //print even the null terminator
       {
           ostr << "="; 
           i++;
       }
       ostr << endl; //new line
       do
       {
           if (index != 0 && index % m_pageSize == 0) //goes as long as it is not 0 and it can be divided by the page size
           {
               cout << "Hit ENTER to continue..."; //telling the user
               cin.get(); //prompt the necessity to press space
           }
           ostr << m_textLines[index].m_value << endl;
           index++;
       } while (index < int(m_noOfLines)); //goes accorddingly to the number of line provided //since num of lines is unsigned, it is changed to an int
       return ostr; //after the showing return ostr
   }

   std::istream& TextFile::getFile(std::istream& istr)
   {
       char filename[TEXT_SIZE];
       istr >> filename; //gets filename input
       while (getchar() != '\n'); //cleans buffer

       setFilename(filename); //set the filename
       setNoOfLines(); //num of lines
       loadText(); // reads text

       return istr; //return istr
   }

   TextFile::operator bool() const //checking if object is valid
   {
       bool ok = false;
       if (this->m_textLines != nullptr || this->m_filename != nullptr) //checking for pointers
       {
           ok = true;
       }
       else
       {
           if (this->m_noOfLines) //checking for value
           {
               ok = true;
           }
       }
       return ok;
   }

   unsigned TextFile::lines() const
   {
       return m_noOfLines; //pass lines as unsigned
   }

   const char* TextFile::name() const
   {
       return m_filename; //pass m_filename as an address
   }

   const char* TextFile::operator[](unsigned index) const
   {
       if (m_textLines == nullptr) // if the array is empty, return as empty
       {
           return nullptr; 
       }
       else
       {
           return m_textLines[index % m_noOfLines]; //make sure it comes back when the array is exceded based on the index
       }
   }

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
   {
       text.view(ostr); //format and output the file in a ostream
       return ostr;
   }

   std::istream& operator>>(std::istream& istr, TextFile& text)
   {
       text.getFile(istr);//acquire proper date from the object in a istream
       return istr;
   }

}