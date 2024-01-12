#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>


using namespace std;

extern double g_taxrate;
extern double g_dailydiscount;


namespace sdds {

	class FoodOrder
	{
		char c_name[10]{};
		char* c_descrip = nullptr ;
		double c_price;
		bool c_isDaily;
	public:
		FoodOrder() {
			c_descrip = nullptr;
		};
		virtual ~FoodOrder() {
			delete[] c_descrip;
		};
		istream& read(istream& istr);
		void display();
		FoodOrder (const FoodOrder& F) {
			operator=(F);
		}; //copy constructor
		FoodOrder& operator=(const FoodOrder& other){
			if (this != &other) {
				delete[] c_descrip;
				c_descrip = new char[strlen(other.c_descrip) + 1];
				strcpy(c_descrip, other.c_descrip);
				strcpy(c_name, other.c_name);
				c_price = other.c_price;
				c_isDaily = other.c_isDaily;
		}
		return *this;
		}; //copy assigment constructor

	};
}

