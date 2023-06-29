/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#include<iostream>
#include<cstring>

#include "Car.h"
#include "Utils.h"

sdds::Car::Car() : Vehicle()
{
	m_carWash = false;
}

sdds::Car::Car(const char* license, const char* model)
{
	if (strlen(license) != 0 && strlen(license) <= sdds::MAX_SIZE_PLT && model && model != nullptr) {
		this->setMakeModel(model);
		this->setLicensePlate(license);
	}
	else {
		Vehicle::setEmpty();
	}
}

sdds::Car::Car(Car& C) 
{
	*this = C;
	this->m_carWash = C.m_carWash;
}

sdds::Car& sdds::Car::operator=(const Car& c)
{
	if (this != &c) {
		Vehicle::setEmpty();
		//this->m_carWash = false;
		Vehicle::operator=(c); //ok copy ok
		this->m_carWash = c.m_carWash;

	}
	return *this;
}

ostream& sdds::Car::writeType(ostream& ostr) const
{
	if (isCsv()) {
		ostr << "C,";
	}
	else {
		ostr << "Vehicle type: Car" << endl;
	}
	return ostr;
}

std::istream& sdds::Car::read(std::istream& istr)
{
	if (isCsv())
	{
		Vehicle::read(istr);
		istr >> m_carWash;
		istr.ignore(100, '\n');
	}
	else
	{
		cout << "\nCar information entry" << endl;
		Vehicle::read(istr);
		cout << "Carwash while parked? (Y)es/(N)o: ";
		m_carWash = Utils::resp(istr);
	}
	return istr;
}

std::ostream& sdds::Car::write(std::ostream& ostr) const
{
	if (isEmpty())
	{
		ostr << "Invalid Car Object" << endl;
	}
	else
	{
		//(isCsv()) ? ostr << "C," : ostr << "Vehicle type: Car" << endl;
		writeType(ostr);

		Vehicle::write(ostr);

		if (isCsv()) {
			ostr << m_carWash << endl;
		}
		else
		{
			if (m_carWash) {
				ostr << "With Carwash" << endl; 
			} 
			else {
				ostr << "Without Carwash" << endl;
			}
		}
	}
	return ostr;
}


