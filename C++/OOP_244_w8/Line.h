/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
#include <iostream>
namespace sdds {
    class Line : public LblShape {
        int m_length;
    protected:
        char* label();
    public:
        Line();
        Line(const char*, int);
        ~Line() {};
        void draw(std::ostream&) const;
        void getSpecs(std::istream&);
    };
}
#endif