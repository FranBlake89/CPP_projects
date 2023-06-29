/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#include <iostream>
#include "Motorcycle.h"
#include "Vehicle.h"
#include "Utils.h"
using namespace std;

namespace sdds
{
	Motorcycle::Motorcycle() :Vehicle() 
	{
		emptyState();
	}
	
	Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel)
	{
		emptyState();
	}

	void Motorcycle::emptyState()
	{
		m_hasSideCarFlag = false;
	}

	Motorcycle::Motorcycle(Motorcycle& m)
	{
		*this = m;
		this->m_hasSideCarFlag = m.m_hasSideCarFlag;
	}

	Motorcycle& Motorcycle::operator=(const Motorcycle& m)
	{
		if (this != &m) {
			setEmpty();
			Vehicle::operator=(m);
			this->m_hasSideCarFlag = m.m_hasSideCarFlag;
		}
		return *this;
	}

	ostream& Motorcycle::writeType(ostream& ostr) const
	{
		if (isCsv()) {
			ostr << "M,";
		}
		else {
			ostr << "Vehicle type: Motorcycle" << endl;
		}
		return ostr;
	}

	std::istream& Motorcycle::read(std::istream& istr)
	{
		if (isCsv())
		{
			Vehicle::read(istr);
			istr >> m_hasSideCarFlag;
			istr.ignore(100, '\n');
		}
		else
		{
			cout << "\nMotorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			m_hasSideCarFlag = Utils::resp(istr);
		}
		return istr;
	}

	std::ostream& Motorcycle::write(std::ostream& ostr) const
	{
		if (isEmpty())
		{
			ostr << "Invalid Motorcycle Object" << endl;
		}
		else
		{
			(isCsv()) ? ostr << "M," : ostr << "Vehicle type: Motorcycle" << endl;

			Vehicle::write(ostr);

			if (isCsv())
			{
				ostr << m_hasSideCarFlag << endl;
			}
			else
			{
				if (m_hasSideCarFlag)
				{
					ostr << "With Sidecar" << endl;
				}
			}
		}
		return ostr;
	}
}