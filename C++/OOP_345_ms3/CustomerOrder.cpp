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
#include "CustomerOrder.h"
#include "Utilities.h"


using namespace std;
namespace sdds
{
	static size_t m_widthField;

	CustomerOrder::CustomerOrder() {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;	
	};

	CustomerOrder::CustomerOrder(const std::string& str) {
		Utilities util;
		size_t next = 0;
		bool more = true;
		m_cntItem = 0;
		m_lstItem = nullptr;
		std::vector<string> tempItems;

		m_name = util.extractToken(str, next, more);
		m_product = util.extractToken(str, next, more);

		while (more) {
			std::string item = util.extractToken(str, next, more);
			if (!item.empty()) {
				tempItems.push_back(item);
				m_cntItem++;
			}
		}

		m_lstItem = new Item* [m_cntItem];
		vector<string>::iterator it = tempItems.begin();

		for (size_t i = 0; it != tempItems.end(); it++, i++) {
			m_lstItem[i] = new Item(tempItems[i]);
			m_lstItem[i]->m_itemName = *(it);
		}
		
		if (m_widthField < util.getFieldWidth())
			m_widthField = util.getFieldWidth();
	};

	CustomerOrder::CustomerOrder(CustomerOrder&& OtherCustomer) noexcept {
		m_cntItem = 0;
		m_lstItem = nullptr;
		operator = (move(OtherCustomer));
	};

	CustomerOrder& CustomerOrder::operator = (CustomerOrder&& OtherCustomer) noexcept {
		if (this != &OtherCustomer) {
			for (size_t i = 0; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			m_lstItem = nullptr;

			m_name = OtherCustomer.m_name;
			m_product = OtherCustomer.m_product;
			m_cntItem = OtherCustomer.m_cntItem;
			m_lstItem = OtherCustomer.m_lstItem;
			
			OtherCustomer.m_name = "";
			OtherCustomer.m_product = "";
			OtherCustomer.m_lstItem = nullptr;
			OtherCustomer.m_cntItem = 0;
		}
		return *this;
	};

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;
	};

	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilledItem == false) {
				return false;
			}
		}
		return (m_cntItem > 0);		
	};

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilledItem == false) {
				return false;
			}
		}
		return true;
		
	};

	CustomerOrder::CustomerOrder(const CustomerOrder& OtherCustomer) {
		throw invalid_argument("ERROR: Cannot make copies.");
	};

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {		
		for (size_t i = 0; i < m_cntItem; i++) {

			if ( !(m_lstItem[i]->m_isFilledItem)) {

				string currentItemName = m_lstItem[i]->m_itemName;

				if (currentItemName == station.getItemName()) {	

					if (station.getQuantity() >= 1) {

						m_lstItem[i]->m_serialNumberItem = station.getNextSerialNumber();
						m_lstItem[i]->m_isFilledItem = true;
						station.updateQuantity();
						os << "    Filled " << m_name << ", " << 
							m_product << " [" << currentItemName << 
							"]" << endl;
						return;
					}
					else {
						os << "    Unable to fill " << m_name << 
							", " << m_product << " [" << 
							currentItemName << "]" << endl;						
					}
				}
			}
		}	
	};

	void CustomerOrder::display(std::ostream& ostr) const {
		ostr << m_name << " - " << m_product << endl;

		for (size_t i = 0; i < m_cntItem; i++) {
			ostr << "[";
			ostr.width(6);
			ostr.fill('0');
			ostr << m_lstItem[i]->m_serialNumberItem;
			ostr << "] ";
			ostr << std::setw(m_widthField);
			ostr.fill(' ');
			ostr.setf(ios::left);
			ostr << m_lstItem[i]->m_itemName;
			ostr.unsetf(ios::left);
			ostr << "   - ";

			if (!(m_lstItem[i]->m_isFilledItem) ) {
				ostr << "TO BE FILLED";
			}
			else {
				ostr << "FILLED";
			}
			ostr << endl;
		}
	
	};

}