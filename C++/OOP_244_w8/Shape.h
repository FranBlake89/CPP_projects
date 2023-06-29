/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
namespace sdds {
    class Shape {
    public:
        virtual ~Shape() {};
        virtual void draw(std::ostream&) const = 0;
        virtual void getSpecs(std::istream&) = 0;
    };
    std::ostream& operator<<(std::ostream& left, const Shape& obj);
    std::istream& operator>>(std::istream& left, Shape& obj);
}
#endif