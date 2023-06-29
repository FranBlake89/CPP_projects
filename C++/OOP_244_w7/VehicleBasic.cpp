/*
Name: Francisco Castillo
Email: fcastillo-rojas1@myseneca.ca
Student ID:
Data: 
Section: 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "VehicleBasic.h"

using namespace std;

namespace sdds
{
	//Private
	void VehicleBasic::setPlate(const char* plate)
	{
		int length = 0;

		if(strlen(plate) > (MAX_SIZE_PL -1) )
		{
			length = (MAX_SIZE_PL - 1);
		}
		else {
			length = strlen(plate);
		}
		strncpy(m_plate, plate, length);
		m_plate[length] = '\0'; //truncate
	}
	void VehicleBasic::setAdd(const char* address)
	{
		int length = 0;
		length = strlen(address);

		if (length > (MAX_SIZE_ADD - 1))
		{
			length = MAX_SIZE_ADD - 1;
		}
		else {
			length = strlen(address);
		}
		strncpy(m_address, address, length);
		m_address[length] = '\0';

	}
	//Public
	VehicleBasic::VehicleBasic(const char* plate, int year)
	{
		const char newCar[MAX_SIZE_ADD] = "Factory";
		
		setPlate(plate);
		setAdd(newCar);

		m_year = year;
	}
	void VehicleBasic::NewAddress(const char* address)
	{
		if (this && (address != this->m_address))
		{
			

			cout << "|";
			cout << right << setfill(' ') << setw(8) << m_plate;
			cout << "| |"; 
			cout << right << setfill(' ') << setw(20) << m_address;
			cout << " ---> "; 
			setAdd(address);
			cout << left << setfill(' ') << setw(20) << address;
			cout << "|" << endl;
		}
	}
	ostream& VehicleBasic::write(ostream& os)const
	{
		os << "| ";
		os << m_year;
		os << " | ";
		os << m_plate;
		os << " | ";
		os << m_address;
		return os;
	}
	istream& VehicleBasic::read(istream& in)
	{
		string plt, add;
		int yr;

		cout << "Built year: ";
		in >> yr;

		cout << "License plate: ";
		in.ignore();
		getline(in, plt);

		cout << "Current location: ";
		getline(in, add);

//copying data to Obj
		m_year = yr;
		setPlate(plt.c_str()); //Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
		setAdd(add.c_str());
		
		return in;
	}
	std::istream& operator>>(std::istream& left, VehicleBasic& obj)
	{
		return obj.read(left);
	}
	std::ostream& operator<<(std::ostream& left, const VehicleBasic& obj)
	{
		return obj.write(left);
	}
}
