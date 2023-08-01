/***********************************************************************
// Final Project Milestone 3
// Module: Streamable
// Filename: Streamable.h
// Version 1.0
// Author	Ana Tirolli
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
// -----------------------------------------------------------
//
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Streamable.h"

namespace sdds {

	std::ostream& operator<<(std::ostream& left, const Streamable& right)
	{
		if (right)
		{
			right.write(left);
		}
		return left;
	}
	std::istream& operator>>(std::istream& left, Streamable& right)
	{
		return right.read(left);
	}
}