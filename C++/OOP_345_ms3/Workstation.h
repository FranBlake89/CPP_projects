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

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <string>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds
{
	extern std::deque<CustomerOrder>g_pending;
	extern std::deque<CustomerOrder>g_completed;
	extern std::deque<CustomerOrder>g_incomplete;

	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_nextStation_ptr;
	public:
		Workstation();
		Workstation(const std::string& str);
		Workstation (const Workstation& Workstation) = delete;
		Workstation(Workstation&& Workstation) = delete;
		Workstation& operator = (const Workstation& Workstation) = delete;
		Workstation& operator = (Workstation&& Workstation) = delete;
		~Workstation();
		void fill(std::ostream& ostr);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& ostr) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif
