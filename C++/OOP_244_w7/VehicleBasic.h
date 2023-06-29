/*
Name: Francisco Castillo
Email: fcastillo-rojas1@myseneca.ca
Student ID:
Data:
Section:
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

using namespace std;

namespace sdds
{
	const int MAX_SIZE_PL = 9;
	const int MAX_SIZE_ADD = 64;

	class VehicleBasic
	{
	protected:
		char m_plate[MAX_SIZE_PL];
		char m_address[MAX_SIZE_ADD];
		int m_year;
		void setPlate(const char* plate);
		void setAdd(const char* address);
	public:
		VehicleBasic() = default;
		~VehicleBasic() = default;
		VehicleBasic(const char* plate, int year);//a custom constructor that receives as parameters the license plate number and the year when the vehicle was built. Set the location of the vehicle at Factory. Assume all data is valid.
		void NewAddress(const char* address); //moves the vehicle to the new address if the new address is different from the current address. Prints to the screen the message
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator <<(std::ostream &left, const VehicleBasic& obj);
	std::istream& operator >>(std::istream &left, VehicleBasic &obj);

}

#endif