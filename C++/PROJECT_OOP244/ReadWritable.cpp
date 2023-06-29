/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include"ReadWritable.h"
#include"Utils.h"

sdds::ReadWritable::ReadWritable()
{
	m_modeRW = false;
}

sdds::ReadWritable::~ReadWritable()
{
	//EMPTY VIRTUAL DESTRUCTOR 
}

bool sdds::ReadWritable::isCsv()const
{
	return m_modeRW;
}

void sdds::ReadWritable::setCsv(bool value)
{
	m_modeRW = value;
}

std::ostream& sdds::operator<<(std::ostream& os, const ReadWritable& rw)
{
	return rw.write(os);
}

std::istream& sdds::operator>>(std::istream& is, ReadWritable& rw)
{
	return rw.read(is);
}
