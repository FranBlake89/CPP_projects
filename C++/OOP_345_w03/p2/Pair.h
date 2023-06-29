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
//This module represents a value-key pair (like the words and their definition in a dictionary).
namespace sdds {


class Pair
{
	std::string m_key{};
	std::string m_value{};

public:
	Pair() {};
	const std::string& getKey() { return m_key; }
	const std::string& getValue() { return m_value; }
	Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};
	//Two objects of type Pair are considered to be equal if they have the same key.
	// In the reflection justify why it was necessary to add each one of the members you have decided to add.
	/*
	Pair& operator==(const Pair& OBJ) {
		
	}*/
	
	//isEmpty
void display(std::ostream& os) const {
		os << std::setw(20) << std::right << m_key << ": " << this->m_value;

	};
/*
Pair& operator==(const Pair& OBJ) {

}*/


};

std::ostream& operator<<(std::ostream& os, const Pair& obj) {
//return obj.display(os);
	obj.display(os);
	return os;
};


bool operator==(Pair& a, Pair& b) {
	return a.getKey() == b.getKey();
}


}