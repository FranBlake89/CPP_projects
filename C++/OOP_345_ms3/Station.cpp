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

#include <iostream>
#include <string>

#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
	static size_t m_widthField = 0;
	static size_t ig_gen = 0;

	Station::Station() {  };

	Station::Station(const std::string& str) {
		size_t next = 0; 
		bool more = true; 
		Utilities util;
		m_name_station = util.extractToken(str, next, more); 
		if (more)m_serialNumber = std::stoi(util.extractToken(str, next, more)); 
		if (more)m_quantity = std::stoi(util.extractToken(str, next, more)); 
		
		if (m_widthField < m_name_station.size()) {
			m_widthField = m_name_station.size();
		}
		if (more)m_description_station = util.extractToken(str, next, more);
		m_id_station = ++ig_gen;
	};

	const std::string& Station::getItemName() const {
		return m_name_station;
	};

	size_t Station::getNextSerialNumber() {
		return m_serialNumber++;
	};

	size_t Station::getQuantity() const {
		return m_quantity;
	};

	void Station::updateQuantity() {
		if (m_quantity > 0) {
			--m_quantity;
		}
	};

	void Station::display(std::ostream& ostr, bool full) const {
		
		ostr.width(3);
		ostr.fill('0');
		ostr << m_id_station << " | ";
		ostr.width(m_widthField);
		ostr.setf(ios::left);
		ostr.fill(' ');
		ostr << m_name_station << "  | ";
		ostr.width(6);
		ostr.setf(ios::right);
		ostr.fill('0');
		ostr << m_serialNumber << " | ";
		ostr.unsetf(ios::right);

		if (full) {
			ostr.width(4);
			ostr.setf(ios::right);
			ostr.fill(' ');
			ostr << m_quantity << " | ";
			ostr.unsetf(ios::right);
			ostr << m_description_station;
		}
		ostr.unsetf(ios::left);
		ostr << endl;
	};
}