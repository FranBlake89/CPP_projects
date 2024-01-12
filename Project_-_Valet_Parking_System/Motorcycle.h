/*
Francisco Catillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_
#include "Vehicle.h"

namespace sdds
{
	class Motorcycle : public Vehicle
	{
	private:
		bool m_hasSideCarFlag;

	public:
		Motorcycle();
		Motorcycle(const char* licensePlate, const char* makeModel);
		void emptyState();
		Motorcycle(Motorcycle& m);
		Motorcycle& operator=(const Motorcycle& m);
		virtual ostream& writeType(ostream& ostr)const;
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout) const;
	};
}

#endif