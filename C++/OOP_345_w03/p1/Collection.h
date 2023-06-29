/*
   ---------------------------------------
Name:		Francisco Castillo
Section:	NDD
   ---------------------------------------
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
//This module represents a family of collections of elements of any data type 
//(for example, collection of ints, or collection of Pairs, etc.).
namespace sdds {

	template <typename T, size_t CAPACITY>

	class Collection
	{
		size_t m_size{};
		T m_items[CAPACITY]{};
		inline static T dummyObj{};

	public:
		Collection() : m_size(0) {};
		virtual ~Collection() {    };
		auto size() { return m_size; }
		void display(std::ostream& os = std::cout) const {

			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;

			for (size_t i = 0; i < m_size; i++)
			{
				//os  << "+++" << m_items[i] << std::endl;
				os << m_items[i] << std::endl;
			}


			os << "----------------------" << std::endl;
		};
		bool add(const T& item) {		
			bool was_Added = false;
		
			if (m_size < CAPACITY) {

				m_items[m_size] = item;
				m_size++;
				was_Added = true;
			}

			return was_Added;
		};
		T operator[] (int index) {
			
			T copy = dummyObj;

			if (sizeof(index) > sizeof(CAPACITY)) {
				
			}
			else {
				copy = m_items[index];
			}	
			return copy;
		};


	};


}