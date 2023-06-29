/*
Name:Francisco Castillo
Email:fcastillo-rojas1@myseneca.ca

*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Dumper.h"
#include "VehicleBasic.h"

namespace sdds
{

	void Dumper::setCapacity(double capacity)
	{

		m_capacity = capacity;
		
	}

	void Dumper::setCrrtLoad(double load)
	{
		this->m_crrtLoad = load;
	}

	Dumper::Dumper(const char* plate, int year, double capacity, const char* address):VehicleBasic(plate, year)
	{
		const double defCrrtLoad = 0;
		setCrrtLoad(defCrrtLoad);
		setCapacity(capacity);
		NewAddress(address);
	}

	bool Dumper::loaddCargo(double cargo)
	{
		bool isLoad = false;

		double delta = m_capacity - m_crrtLoad - cargo;
		if (delta >= 0.0)
		{
			m_crrtLoad += cargo;
			isLoad = true;
		}

		return isLoad;
	}

	bool Dumper::unloadCargo()
	{
		bool isUnload = false;

		if (this->m_crrtLoad != 0) {
			this->m_crrtLoad = 0;
			isUnload = true;
		}

		return isUnload;
	}

	std::ostream& Dumper::write(std::ostream& os)const
	{
		os << "| ";
		os << m_year;
		os << " | "; 
		os << m_plate;
		os << " | ";
		os << m_address;
		os << " | "; 
		os << m_crrtLoad; 
		os << "/";
		os << m_capacity;
		return os;
	}

	std::istream& Dumper::read(std::istream& in)
	{
		string plt, add;
		int yr;
		double cap, cargo;

		cout << "Built year: "; 
		in >> yr;
		
		cout << "License plate: ";
		in.ignore();
		getline(in, plt);

		cout << "Current location: ";
		getline(in, add);

		cout << "Capacity: ";
		
		in >> cap;

		cout << "Cargo: ";
		in >> cargo;

		//copying data to Obj
		m_year = yr;
		setPlate(plt.c_str()); //Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
		setAdd(add.c_str());
		setCapacity(cap);
		setCrrtLoad(cargo);
		
		return in;
	}
	std::ostream& operator<<(std::ostream& left, const Dumper& obj)
	{
		return obj.write(left);
	}
	std::istream& operator>>(std::istream& istr, Dumper& obj)
	{
		return obj.read(istr);
	}
}
