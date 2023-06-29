/*/=================================================//
~~~~~~~~Francisco Castillo
~~~~~~~~fcastillo-rojas1@myseneca.ca
//=================================================/*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Basket.h"
namespace sdds {

	// default constructor
	Basket::Basket()
	{
		m_fruits = NULL;
		m_count = 0;
		m_price = 0;
	}

	// parameterized constructor
	Basket::Basket(Fruit* fruits, int size, double price) : m_fruits(NULL), m_count(0), m_price(0)
	{
		// check if all parameters are valid
		if ((fruits != NULL) && (size > 0) && (price > 0))
		{
			m_count = size;
			// create a Fruit array of size
			m_fruits = new Fruit[size];
			// loop to copy the fruits array
			for (int i = 0; i < size; i++)
			{
				strcpy(m_fruits[i].m_name, fruits[i].m_name);
				m_fruits[i].m_quantity = fruits[i].m_quantity;
			}
			// set the price
			m_price = price;
		}
	}

	// copy constructor
	Basket::Basket(const Basket& basket)
	{
		m_fruits = NULL;
		m_count = 0;
		m_price = 0;
		// check if fruits of basket is not empty
		if (basket.m_fruits != NULL)
		{
			// deep copy of basket into current object
			m_count = basket.m_count;
			m_price = basket.m_price;
			m_fruits = new Fruit[m_count];
			for (int i = 0; i < m_count; i++)
			{
				strcpy(m_fruits[i].m_name, basket.m_fruits[i].m_name);
				m_fruits[i].m_quantity = basket.m_fruits[i].m_quantity;
			}
		}
	}

	Basket::~Basket() //destructor
	{
		if (m_fruits != NULL)
		{
			delete[] m_fruits;
		}
	}

	// function to set the price
	void Basket::setPrice(double price)
	{
		m_price = price;
	}

	// returns true if the basket contains any fruits and false otherwise.
	Basket::operator bool() const { return m_fruits != NULL; }

	// overloading of += operator
	Basket& Basket:: operator+=(Fruit fruit)
	{
		// check if fruits array is empty
		if (m_fruits != NULL)
		{
			// create a temporary array of size m_count+1
			Fruit* temp = new Fruit[m_count + 1];
			// loop to copy the fruits from m_fruits to temp array
			for (int i = 0; i < m_count; i++)
			{
				strcpy(temp[i].m_name, m_fruits[i].m_name);
				temp[i].m_quantity = m_fruits[i].m_quantity;
			}

			delete[] m_fruits; // delete the existing fruits array
			m_count++;
			// create another m_fruits array of size 1 more than existing array
			m_fruits = new Fruit[m_count];
			// copy the fruits back to m_fruits array
			for (int i = 0; i < m_count - 1; i++)
			{
				strcpy(m_fruits[i].m_name, temp[i].m_name);
				m_fruits[i].m_quantity = temp[i].m_quantity;
			}
			// add fruit to end of m_fruits
			m_fruits[m_count - 1] = fruit;
			delete[] temp; 
		}
		else
		{
			// empty m_fruits array
			m_count++;
			// create m_fruits of size 1
			m_fruits = new Fruit[m_count];
			// copy the fruit to end of m_fruits
			m_fruits[0] = fruit;
		}


		return *this; // return the updated object

	}

	// overloading insertion operator
	ostream& operator<<(ostream& out, const Basket& basket)
	{
		// if basket is empty
		if (basket.m_count == 0)
		{
			out << "The basket is empty!" << endl;
		}
		else
		{
			// non-empty basket
			out << "Basket Content:" << endl;
			out << fixed << setprecision(2);
			for (int i = 0; i < basket.m_count; i++)
			{
				out << right << setw(10) << basket.m_fruits[i].m_name << ": " << basket.m_fruits[i].m_quantity << "kg" << endl;
			}

			out << "Price: " << basket.m_price << endl;
		}

		return out;
	}

}