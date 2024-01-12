/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include "Vehicle.h"
#include "Utils.h"

using namespace std;
namespace sdds {

	Vehicle::Vehicle()
	{
		setEmpty();
	}
	Vehicle::Vehicle(const char* license, const char* model, const int parkingNUm)
	{
		if (license && strlen(license) <= MAX_SIZE_PLT && strlen(license) != 0 && model && strlen(model) >= 2) {
			setLicensePlate(license); //ADD IN  MS4
			setMakeModel(model); 
			m_spotNumber = parkingNUm;
			m_empty = false;
		}
		else {
			//m_empty = true; //DELETE REDUNDANCY IN MS4
			setEmpty();
		}
	}

	Vehicle::~Vehicle()
	{
		setEmpty(); 
	}

	void Vehicle::setEmpty()
	{
		if (m_model) { 
			delete[] m_model;
			m_model = nullptr;
		}

		m_plate[0] = '\0';
		m_model = nullptr;
		m_spotNumber = 0;
		m_empty = true;
	}
	//NEW FUNCTION CREATED ON MS4
	void Vehicle::setLicensePlate(const char* license)
	{

		if (license && strlen(license) <= MAX_SIZE_PLT && strlen(license) != 0) {
			strncpy(m_plate, license, MAX_SIZE_PLT);
		}

	}
	/****************************/
	void Vehicle::setMakeModel(const char* model)
	{
		if (model != nullptr && strlen(model) >= 2 && strlen(model) <= 60) {

			if (m_model) {
				delete[] m_model;
				m_model = nullptr;
			}

			size_t size = strlen(model) + 1;
			m_model = new char[size];
			strncpy(m_model, model, size);
		}
		else {

			setEmpty();
		}

	}
	void Vehicle::setParkingSpot(int valueSpot)
	{
		if (valueSpot >= 0) {
			m_spotNumber = valueSpot;
		}
		else {
			setEmpty();
		}
	}
	bool Vehicle::isEmpty() const
	{
		bool isEmpty = false;
		if (m_model == nullptr && m_empty == true) {
			isEmpty = true;
		}
		return isEmpty;
	}

	const char* Vehicle::getLicensePlate() const
	{
		return m_plate;
	}

	const char* Vehicle::getMakeModel() const
	{
		return m_model;
	}


	int Vehicle::getParkingSpot() const
	{
		return m_spotNumber;
	}
	/*************** TRY TO DO IT AGAIN ********************************************/
	Vehicle::Vehicle(Vehicle& v)
	{
		//*this=v;
		strncpy(m_plate, v.getLicensePlate(), sizeof(v.getLicensePlate()));

		//	m_model = (char*) (v.getMakeModel());
		this->setMakeModel(v.m_model);
		m_spotNumber = v.getParkingSpot();
		m_empty = false;
	}
	/***********************************************************/
	Vehicle& Vehicle::operator=(const Vehicle& V)
	{
		if (this != &V) {
			setEmpty();

			strncpy(this->m_plate, V.getLicensePlate(), strnlen(V.getLicensePlate(), 9));
			this->setCsv(V.isCsv());
			this->setMakeModel(V.m_model);
			//this->setParkingSpot(V.m_spotNumber);
			this->m_spotNumber = V.getParkingSpot();
			this->m_empty = false;
		}
		return *this;
	}

	bool Vehicle::operator==(const char* plate) const //1st
	{
		bool identical = false;
		Utils::upperString(plate);
		Utils::upperString(this->getLicensePlate());

		if (!this->m_plate || plate == nullptr) {
			identical = false;
		}
		else {

			if (strcmp(this->m_plate, plate))
				identical = true;

		}

		return identical;
	}
	bool Vehicle::operator==(const Vehicle& v) const//2nd
	{

		bool identical = false;
		Utils::upperString(v.m_plate);
		Utils::upperString(this->getLicensePlate());

		if (!this->m_plate || !v.m_plate) {
			identical = false;
		}
		else {

			if (strcmp(this->m_plate, v.m_plate))
				identical = true;

		}

		return identical;
	}
	std::istream& Vehicle::read(std::istream& istr)
	{
		int parkingSpot;
		char makeModel[61] = {};

		// check comma separated
		if (isCsv())
		{
			istr >> parkingSpot;
			istr.ignore(1, ',');
			istr.getline(m_plate, MAX_SIZE_PLT + 1, ',');
			Utils::toUpper(m_plate);
			istr.getline(makeModel, 60, ',');


			setParkingSpot(parkingSpot);
			setMakeModel(makeModel);
		}
		else
		{
			cout << "Enter License Plate Number: ";
			Utils::read(m_plate, 1, MAX_SIZE_PLT, "Invalid License Plate, try again: ", istr);
			cout << "Enter Make and Model: ";
			Utils::read(makeModel, 2, 60, "Invalid Make and model, try again: ", istr); //STR
			if (istr)
			{
				setMakeModel(makeModel);
				Utils::toUpper(m_plate);
			}
			else
			{
				setEmpty();
			}
		}

		return istr;
	}

	std::ostream& Vehicle::write(std::ostream& ostr) const
	{
		if (isEmpty())
		{
			ostr << "Invalid Vehicle Object" << endl;
		}
		else
		{
			//writeType();
			// check comma separated
			if (isCsv())
			{
				ostr << m_spotNumber << "," << m_plate << "," << m_model << ",";
			}
			else
			{
				ostr << "Parking Spot Number: ";
				if (m_spotNumber == 0) {
					ostr << "N/A" << endl;
				}
				else {
					ostr << m_spotNumber << endl;
				}
				ostr << "License Plate: " << m_plate << endl;
				ostr << "Make and Model: " << m_model << endl;
			}
		}
		return ostr;

	}
}
