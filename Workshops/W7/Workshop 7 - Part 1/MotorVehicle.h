/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Carolline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-17

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H
#include <iostream>
#include "cstring.h"

namespace sdds {

	class MotorVehicle {
		char m_plate[9]; //license plate with a limit of 9
		char m_location[64]; //location with a limit of 64
		int m_fabricationYear; //didn't specify limit

	public:
		MotorVehicle(const char* plate, int fabricationYear); //custom constructor
		void moveTo(const char* location); //Moves the vehicle to another place
		std::ostream& write(std::ostream& os) const; //format
		std::istream& read(std::istream& is); //get user input
	};

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& motorVehicle); //call write
	std::istream& operator>>(std::istream& is, MotorVehicle& motorVehicle); //call read
}
#endif // !MOTORVEHICLE_H