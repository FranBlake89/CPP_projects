/*
   ---------------------------------------
Name:		Francisco Castillo
Seneca Id:	148904212
e-mail:		fcastillo-rojas1@myseneca.ca
Section:	NDD
   ---------------------------------------
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;

namespace sdds {

	class ProteinDatabase
	{
		string* seqProtein{};
		size_t numProtein{};
	public:
		ProteinDatabase();

		//read file
		ProteinDatabase(const char* fileName);

		size_t size() const;
		std::string operator[](size_t index) const;

		//Rule of five
		//	copy constrcutor 
		ProteinDatabase(const ProteinDatabase& obj);
		//	 Copy Assignment Operator
		ProteinDatabase& operator=(const ProteinDatabase& obj);
		//	Move constructor (part 2)
		ProteinDatabase(ProteinDatabase&& obj) noexcept;
		// move assignment operator (part 2)
		ProteinDatabase& operator=(ProteinDatabase&& obj)noexcept;
		//	Destructor
		virtual ~ProteinDatabase();

		

	};

}

