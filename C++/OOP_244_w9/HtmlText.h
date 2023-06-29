/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef SDDS_HtmlText_H
#define SDDS_HtmlText_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "Text.h"

namespace sdds
{
    class HtmlText : public Text
    {

        char* m_title = nullptr;

    public:
        HtmlText();
        HtmlText(const char* ro);
        HtmlText& operator=(const HtmlText& ro);
        void setTitle(const char* title);
        ~HtmlText();
        std::ostream& write(std::ostream& ostr) const;
    };
    std::istream& operator>>(std::istream& istr, HtmlText& ro);
    std::ostream& operator<<(std::ostream& ostr, const HtmlText& ro);
}

#endif 