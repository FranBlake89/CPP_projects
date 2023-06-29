/*
Name:Francisco Castillo
Email:fcastillo-rojas1@myseneca.ca

*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	class Dumper:public VehicleBasic
	{
		double m_capacity;
		double m_crrtLoad; //current load of cargo, can't exceed the capacity.
		void setCapacity(double capacity);
		void setCrrtLoad(double load);
	public:
		Dumper(const char* plate, int year, double capacity, const char* address);
		bool loaddCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& left, const Dumper& obj);
	std::istream& operator>>(std::istream& istr, Dumper& obj);

}
#endif