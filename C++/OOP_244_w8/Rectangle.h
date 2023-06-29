/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
#include <iostream>
namespace sdds {
    class Rectangle : public LblShape {
        int m_width, m_height;
    public:
        Rectangle();
        ~Rectangle() {};
        void draw(std::ostream&) const;
        void getSpecs(std::istream&);
        Rectangle(const char*, int, int);
    };
}
#endif