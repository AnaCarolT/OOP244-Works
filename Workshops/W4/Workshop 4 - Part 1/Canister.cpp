/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-06-08

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

	double PI = 3.14159264;

	void Canister::setToDefault()  //Set all the variables in Canister to a default value.
	{
		m_contentName = nullptr; //safe state.
		m_diameter = 10.0; //values provided.
		m_height = 13.0;   //values provided.
		m_contentVolume = 0.0; //safe state.
		m_usable = true; //it's true until proved otherwise.
	}
   
	void Canister::setName(const char* Cstr) 
	{
		if (Cstr != nullptr) //check if it's valid
		{
			if (m_usable) //if m_usable is true 
			{
				delete[] m_contentName; //standard procedure to avoid memory leak
				m_contentName = new char[strLen(Cstr) + 1]; //allocate memory for new name
				strCpy(m_contentName, Cstr); //copy the name 
			}
		}
	}

	bool Canister::isEmpty()const //remember it's a bool
	{
		return m_contentVolume < 0.00001; //It will return true if it's less than 0.00001 (ContentVolume)
	}

	bool Canister::hasSameContent(const Canister& C)const //checking if both have a name and then checking if it's identical
	{
		if (m_contentName == nullptr || C.m_contentName == nullptr) //checking if any name is empty
		{
			return false;
		}
		if (strCmp(m_contentName, C.m_contentName) == 0) //0 means the names are equal (remember)
		{
			return true; //equal
		}
		else
		{
			return false;
		}
	}

	Canister::Canister() //First constructor
	{
		setToDefault(); //Setting the proper values
	}

	Canister::Canister(const char* contentName) //Second constructor
	{
		setToDefault(); //Setting the proper values
		setName(contentName); //adding contentName
	}

	Canister::Canister(double height, double diameter, const char* contentName) //Third constructor
	{
		setToDefault(); //Setting the proper values
		if (height >= 10.0 && height <= 40.0) //first validation to check if height is inside the acceptable parameters
		{
			if (diameter >= 10.0 && diameter <= 30.0) //second validation to check if the diameter is inside the acceptable parameters
			{
				//if both are true the values are copied.
				m_height = height;
				m_diameter = diameter;
				setName(contentName); //adding name
			}
			else
			{
				m_usable = false; //In case it fail the second test.
			}
		}
		else
		{
			m_usable = false; //In case it fail both.
		}
	}

	Canister::~Canister() 
	{
		delete[] m_contentName; //desconstructor.
	}

	Canister& Canister::setContent(const char* contentName) //checking according to the steps provided in the workshop
	{
		if (contentName == nullptr) //if it's null, the canister is unusable
		{
			m_usable = false;
		}
		if (isEmpty()) //If Canister is empty
		{
			setName(contentName);  //set name 
		}
		else
		{
			if (!hasSameContent(contentName)) //if the content names are not similar, canister is unusable
			{
				m_usable = false;
			}
		}
		return *this;
	}

	Canister& Canister::pour(double quantity) 
	{
		if (m_usable && quantity > 0 && (quantity + m_contentVolume) <= capacity()) //checks if the quantity fits the canister, quantity needs to be more than 0.
		{
			m_contentVolume += quantity;
		}
		else //if doesn't meet the proper conditions, the canister is unusable
		{
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C) 
	{
		//Set the content name to the Canister argument using setContent().
		setContent(C.m_contentName);

		if (C.volume() > (capacity() - volume())) //if the volume() of the argument is greater than the capacity() minus the volume()
		{
			//Reduce the content volume of the argument by capacity() minus volume() and then set the content volume to capacity()
			C.m_contentVolume = C.m_contentVolume - (capacity() - volume());
			m_contentVolume = capacity();
		}
		else
		{
			//else pour the content volume of the argument using pour() method and set the content volume of the argument to 0.0.
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.0;
		}
		return *this; //return the object
	}

	double Canister::volume()const //getting the volume
	{
		return m_contentVolume;
	}

	std::ostream& Canister::display()const //count based on the sample output.
	{
		//tittle already appears
		cout.precision(1); //1 decimal
		cout.width(7); //reserve 7 spaces
		cout<< fixed << capacity(); //fix the display of the number
		cout << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (m_usable == true)
		{
			if (m_contentName != nullptr) // it only appear if there is a content name
			{
				cout << " of ";
				cout.width(7);
				cout << m_contentVolume;
				cout << "cc   " << m_contentName;
			}
		}
		else
		{
			cout << " of Unusable content, discard!"; //when it returns false
		}
		return cout; //multiple operations with cout
	}

	double Canister::capacity()const 
	{
		double capacity; //calculating the capacity
		capacity = PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2); //PI is in the global scope
		return capacity;
	}

	void Canister::clear() //set an unusable canister to empty
	{
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}
}