/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
#include <iostream>
namespace sdds {
    class LblShape : public Shape {
        char* m_label = nullptr;
    protected:
        char* label() const;
    public:
        LblShape();
        LblShape(const char*);
        virtual ~LblShape();
        void getSpecs(std::istream&);
        LblShape(const LblShape&) = delete;
        void operator=(const LblShape&) = delete;
        virtual void draw(std::ostream&) const = 0;
    };
}
#endif