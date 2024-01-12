
/*
> Name: Francisco Castillo
> Course: OOP
> Section: NDD
> Seneca ID: 148904212
> Seneca email: fcastillo-rojas1@myseneca.ca
> Date of completion: 2023-mm-dd

* I confirm that I am the only author of this file
 and the content was created entirely by me.
*/
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>
#include <string>

namespace sdds
{
	class Station
	{
		size_t m_id_station;
		std::string m_name_station;
		std::string m_description_station;
		size_t m_serialNumber;
		size_t m_quantity;
		
	public:
		Station();
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif