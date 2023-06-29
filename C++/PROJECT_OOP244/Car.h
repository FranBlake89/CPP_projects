/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef SSDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
namespace sdds {
	
	class Car : public Vehicle
	{
		bool m_carWash = false;
	public:
		Car();
		Car(const char* license, const char* model);
		Car(Car& c);//check this
		Car& operator= (const Car& c); //check this
		virtual ostream& writeType(ostream& ostr)const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

}


#endif