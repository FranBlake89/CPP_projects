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

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <iostream>
#include <string>
#include "Station.h"

namespace sdds
{
	class CustomerOrder
	{		
		struct Item
		{
			std::string m_itemName{};
			size_t m_serialNumberItem{ 0 };
			bool m_isFilledItem{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string m_name;	
		std::string m_product;
		size_t m_cntItem{0};
		Item** m_lstItem = nullptr;
	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder (const CustomerOrder& OtherCustomer);
		CustomerOrder (CustomerOrder&& OtherCustomer) noexcept;
		CustomerOrder& operator = (const CustomerOrder& OtherCustomer) = delete;
		CustomerOrder& operator = (CustomerOrder&& OtherCustomer) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& ostr);
		void display(std::ostream& ostr) const;
	};
}
#endif