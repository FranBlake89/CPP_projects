/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#include "Line.h"
#include <cstring>
#include <string>
using namespace std;
namespace sdds {
    Line::Line()
    {
        m_length = 0;
    }
    Line::Line(const char* label, int length) :LblShape(label)
    {
        m_length = length;
    }
    void Line::getSpecs(std::istream& istr)
    {
        LblShape::getSpecs(istr);
        istr >> m_length;
        istr.ignore(500, '\n');
    }
    void Line::draw(std::ostream& ostr) const
    {
        if (m_length > 0 && LblShape::label() != nullptr)
        {
            string Wrd;
            Wrd = LblShape::label();

            int lengWrd = Wrd.length();

            ostr << LblShape::label();

            for (int i = 0; i < (m_length - lengWrd); i++)
                ostr << "=";
        }
    }
}