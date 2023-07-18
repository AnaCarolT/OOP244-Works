/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-17

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds {

	//Inside class
	MotorVehicle::MotorVehicle(const char* plate, int fabricationYear)
	{
		//a custom constructor that receives as parameters the license plate number and the year
		//Set the location of the vehicle at Factory. Assume all data is valid.
		strnCpy(m_plate, plate, 8);
		m_plate[8] = '\0';
		strCpy(m_location, "Factory");
		m_fabricationYear = fabricationYear;
	}

	void MotorVehicle::moveTo(const char* location)
	{
		if (location != m_location) //moves the vehicle to the new address if the new address is different from the current address.
		{   
			cout << "|";
			cout.width(8); //8 spaces
			cout << right << m_plate; //the license plate is a field of 8 characters aligned to the right
			cout << "| |";
			cout.width(20); //20 spaces
			cout << right << m_location; //current address is a field of 20 characters aligned to the right
			cout << " " << "--->" << " "; //lil arrow like the demonstration
			cout.width(20); //20 spaces
			cout << left << location; //new address is a field of 20 characters aligned to left
			cout << "|" << endl;
			strnCpy(m_location, location, 63);  
			m_location[63] = '\0';
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const //formatted printing
	{
		os << "| " << m_fabricationYear << " | " << m_plate << " | " << m_location;
		return os; //printing according to the sample
	}

	std::istream& MotorVehicle::read(std::istream& is) //read data
	{
		//assuming everything is right
		cout << "Built Year: ";
		is >> m_fabricationYear; //get build year
		cout << "License Plate: ";
		is >> m_plate; // get license plate
		cout << "Current Location: ";
		is >> m_location; //get current location
		return is;
	}

	//outside class

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& motorVehicle)
	{
		return motorVehicle.write(os); //extract
	}

	std::istream& operator>>(std::istream& is, MotorVehicle& motorVehicle)
	{
		return motorVehicle.read(is); //insert
	}

}