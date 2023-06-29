
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
#include <iomanip>
#include <vector>
#include "Utilities.h"
#include "Workstation.h"

using namespace std;
namespace sdds
{

	Workstation::Workstation() {
		m_nextStation_ptr = nullptr;
	};

	Workstation::Workstation(const string& str) : Station(str) {
		m_nextStation_ptr = nullptr;	
	};

	Workstation::~Workstation() {};

	void Workstation::fill(std::ostream& ostr) {
		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, ostr);
		}
	};

	bool Workstation::attemptToMoveOrder() {
		if (!m_orders.empty()) {
			CustomerOrder& ref = m_orders.front();
			if (ref.isItemFilled(this->getItemName()) == true || this->getQuantity() == 0) {
				if (this->getNextStation() == nullptr) {
					if (ref.isOrderFilled() == true) {
						g_completed.push_back(move(ref));
					}
					else {
						g_incomplete.push_back(move(ref));
					}
				}
				else {
					(*(this->m_nextStation_ptr)) += std::move(ref);
				}
				m_orders.pop_front();
				return true;
			}
		}
		return false;
	};

	void Workstation::setNextStation(Workstation* station) {
		m_nextStation_ptr = station;
	};
	
	Workstation* Workstation::getNextStation() const {
		return m_nextStation_ptr;
	};
	
	void Workstation::display(std::ostream& ostr) const {
		if (m_nextStation_ptr == nullptr) {
			ostr << getItemName() << 
				" --> End of Line" << 
				endl;
		}
		else {
			ostr << 
				getItemName() << 
				" -->" << getNextStation() << 
				endl;
		}
	};
	
	Workstation& Workstation::operator += (CustomerOrder&& newOrder) {
		m_orders.push_back(move(newOrder));
		return *this;
	};
}

