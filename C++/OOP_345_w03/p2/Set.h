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
#include <cmath>
#include <cstdlib>

#include "Pair.h"
#include "Collection.h"

namespace sdds {
    template<class T>
    class Set : public Collection<T, 100> {

        const size_t CAPACITY = 100;

    public:

        Set() { ; }

        bool add( const T& item) {
            auto a = item;

            for (size_t i = 0; i < this->m_size; i++)
            {
                auto b = this->m_items[i];
                if (a == b)
                {
                    return false;
                }
            }

            return Collection<T, 100>::add(item);
        }

    };

    template<>
    class Set<double> : public Collection<double, 100> {

        const size_t CAPACITY = 100;

    public:

        Set() { ; }

        bool add(const double& item) {

            for (size_t i = 0; i < this->m_size; i++)
            {
                if (std::fabs(item - this->m_items[i]) <= 0.01)
                {
                    return false;

                }
            }

            return Collection<double, 100>::add(item);
        }

    };


}