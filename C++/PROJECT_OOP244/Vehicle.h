/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_

#include "ReadWritable.h"

using namespace std;
namespace sdds {
	const int MAX_SIZE_PLT = 8; //CHANGE NAME VARIABLE ON MS4

	class Vehicle : public ReadWritable
	{
		char m_plate[MAX_SIZE_PLT + 1] = {};
		char* m_model = nullptr; // This value can not be a null address and must be minimum of two characters.
		int m_spotNumber = 0; //can be a zero or positive integer number. A Vehicle with a zero (0) parking spot number is considered a vehicle that is not parked.
		bool m_empty;
	protected:
		void setEmpty();
		bool isEmpty() const; //before was public
		const char* getMakeModel() const;
		void setMakeModel(const char* model);
		void setLicensePlate(const char* license);
	public:
		const char* getLicensePlate() const; //before was public
		Vehicle();
		Vehicle(const char* license, const char* model, const int parkingNum = 0);
		Vehicle(Vehicle& V);
		Vehicle& operator=(const Vehicle& V);
		virtual ~Vehicle();
		int getParkingSpot() const;
		void setParkingSpot(int valueSpot);
		bool operator==(const char* plate)const;//  compares two licence plate of vehicles
		bool operator==(const Vehicle& v) const;//  compares two vehicles
		std::istream& read(std::istream& istr = std::cin);
		virtual std::ostream& writeType(std::ostream& ostr = std::cout) const = 0;
		std::ostream& write(std::ostream& ostr = std::cout) const;
	};


}
#endif