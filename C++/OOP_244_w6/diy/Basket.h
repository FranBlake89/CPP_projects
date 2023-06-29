/*/=================================================//
~~~~~~~~Francisco Castillo
~~~~~~~~fcastillo-rojas1@myseneca.ca
//=================================================/*/
#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{

	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_quantity; // quantity KG
	};

	class Basket
	{

		Fruit* m_fruits; 
		int m_count;
		double m_price;

	public:
		Basket(); // default constructor
		Basket(Fruit* fruits, int size, double price);// parameterized constructor
		Basket(const Basket& basket);// copy constructor
		~Basket(); //destructor
		void setPrice(double price);// function to set the price
		operator bool() const;// returns true if the basket contains any fruits and false otherwise.
		Basket& operator+=(Fruit fruit);// overloading insertion operator
		friend ostream& operator<<(ostream& out, const Basket& basket);

	};

}
#endif