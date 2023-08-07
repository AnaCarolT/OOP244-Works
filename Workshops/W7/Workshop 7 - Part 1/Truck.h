/*///////////////////////////////////////////////////////////////////////////
Full name: Ana Caroline Campos Tirolli
Student ID#:122476229
Email: acampos-tirolli@myseneca.ca
Date: 2023-07-17

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.

///////////////////////////////////////////////////////////////////////////*/

#ifndef TRUCK_H
#define TRUCK_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MotorVehicle.h"

namespace sdds {

	class Truck : public MotorVehicle
	{
		//V a capacity in kilograms as a floating-point number in double precision; this is the maximum weight of the cargo the truck can carry
		double m_limit;
		//V the current cargo load (in kilograms) is a floating-point number in double precision; the load cannot exceed the capacity.
		double m_currentweight;

	public:

		Truck(const char* plate, int fabricationYear, double limit, const char* location); //custom constructor
		bool addCargo(double weight); //a mutator that adds to the attribute that stores the current cargo load the weight specified as a parameter.
		bool unloadCargo(); //a mutator that unloads current cargo (sets the attribute to 0).
		std::ostream& write(std::ostream& os) const; //formatted printing
		std::istream& read(std::istream& is); //get user input
	};

	std::ostream& operator<<(std::ostream& os, const Truck& truck); //write
	std::istream& operator>>(std::istream& is, Truck& truck); //read
}
#endif // !TRUCK_H




