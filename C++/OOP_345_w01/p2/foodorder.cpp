/*
   ---------------------------------------
Name:		Francisco Castillo
Seneca Id:	148904212
e-mail:		fcastillo-rojas1@myseneca.ca
Section:	NDD
   ---------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

#include "foodorder.h"

using namespace std;
using namespace sdds;

double g_taxrate;
double g_dailydiscount;

namespace sdds {
    static int counter = 1;
}

istream& FoodOrder::read(istream& istr)
{
    if (istr.good()) {
        //Set Empty state
        delete[] c_descrip;
        c_descrip = nullptr;

        //Read data
        string name{};
        getline(istr, name, ',');

        string foodDesc{};
        getline(istr, foodDesc, ',');

        double price = -1;
        istr >> price;
        istr.ignore();

        char daily{};
        istr >> daily;

        //Set values      

        strncpy(c_name, name.c_str(), 9);

        c_descrip = new char[foodDesc.length() + 1];
        strncpy(c_descrip, foodDesc.c_str(), foodDesc.length() + 1);

        c_price = price;

        if (daily == 'Y') { c_isDaily = true; }
        else if (daily == 'N') { c_isDaily = false; }
        
        

    }
    return istr;
}

void FoodOrder::display()
{
    if ( strlen(c_name) != 0 ) {
        cout << setw(2) << left << counter << ". "
            << setw(10) << left << c_name << "|"
            << setw(25) << left << c_descrip << "|"
            << setw(12) << left << fixed << setprecision(2)
            << c_price * (1 + g_taxrate) << "|";

        if (c_isDaily) {
            cout << setw(13) << right << fixed << setprecision(2)
                << ((c_price * (1 + g_taxrate)) - (g_dailydiscount)) << endl;
        }
        else {
            cout << endl;
        }
        counter++;
    }
    else if (c_name[0] == '\0') {
        cout << counter++ << ". No Order" << endl;
    }
}
/*
FoodOrder& FoodOrder::operator=(const FoodOrder& ro)
{
    //Set Empty
    delete[] c_descrip;
    c_descrip = nullptr;

    //Copy data
    strcpy(this->c_name, ro.c_name);

    this->c_descrip = new char[strlen(ro.c_descrip) + 1];
    strcpy(this->c_descrip, ro.c_descrip);

    c_price = ro.c_price;

    c_isDaily = ro.c_isDaily;

    return *this;
}

*/