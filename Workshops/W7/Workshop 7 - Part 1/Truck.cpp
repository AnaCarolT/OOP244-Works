/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-17

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#include "Truck.h"

using namespace std;

namespace sdds {

	//inside class
	//Call the constructor from the base class and pass the license number and year to it.
	Truck::Truck(const char* plate, int fabricationYear, double limit, const char* location) : MotorVehicle(plate, fabricationYear)
	{
		m_limit = limit; //limit needs to be initialized.
		m_currentweight = 0; //Set the current cargo to 0
		moveTo(location); //move the truck to the address specified in the last parameter.
	}

	bool Truck::addCargo(double weight) //adds weight to the current weight
	{
		//organized exactly like the sample output
		double addedWeight = m_currentweight + weight;
		bool ok = false;
		if (weight > 0) //Cant be negative numbers
		{
			if (m_currentweight != m_limit) //if they try adding again after going over the limit
			{
				//going according to output
				if (addedWeight <= m_limit) //its gonna add if both together are not over the limit
				{
					m_currentweight += weight; //adds under or until the limit
					ok = true;
				}
				else
				{
					m_currentweight = m_limit; //adds until the limit
					ok = true;
				}
			}
		}
		return ok;
	}

	bool Truck::unloadCargo()
	{
		bool ok = false;
		if (m_currentweight > 0) //if there is any weight
		{
			m_currentweight = 0; //clean weight
			ok = true; //return cleaned
		}
		return ok; //retrun impossible to clean what is empty
	}

	std::ostream& Truck::write(std::ostream& os) const //print formatted
	{
		MotorVehicle::write(os); //invoking the base write
		os << " | ";
		cout << m_currentweight << "/" << m_limit; //prints the current weight and the limit
		return os;

	}

	std::istream& Truck::read(std::istream& is)
	{
		MotorVehicle::read(is); //invoking the base read
		cout << "Capacity: ";
		is >> m_limit; //asks the capacity
		cout << "Cargo: ";
		is >> m_currentweight; //asks the current weight
		return is;
	}

	//outside class

	std::ostream& operator<<(std::ostream& os, const Truck& truck)
	{
		return truck.write(os); //print
	}

	std::istream& operator>>(std::istream& is, Truck& truck)
	{
		return truck.read(is); //ask for data
	}

}