/*
   ---------------------------------------
Name:		Francisco Castillo
Seneca Id:	148904212
e-mail:		fcastillo-rojas1@myseneca.ca
Section:	NDD
   ---------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>
#include <cstring>

#include "ProteinDatabase.h"

using namespace sdds;

sdds::ProteinDatabase::ProteinDatabase()
{
	//default
}

sdds::ProteinDatabase::ProteinDatabase(const char* fileName)
{ 
	string line;

	std::ifstream fileStream(fileName);

	// i. reads the file to count the number of protein sequence present in the file.
	size_t proteinCount = 0;

	if (fileStream.is_open()) {
		while (getline(fileStream, line))
		{
			if (line[0] == '>')
				proteinCount++;
		}

		numProtein = proteinCount;
		fileStream.close();
	}

	// ii. allocates memory for that number of protein sequences in the array
	seqProtein = new string[numProtein + 1];

	// iii. re-reads the file and loads the protein sequences (i.e., string of characters not sequence names) into the array.
	proteinCount = 0;

	fileStream.open(fileName);


	if (fileStream.is_open()) {
		while (getline(fileStream, line) && proteinCount < numProtein)
		{
			if (line[0] != '>') {
				seqProtein[proteinCount] += line;
			}

			if (line[0] == '>' && !seqProtein[proteinCount].empty()) {
				proteinCount++;
			}
		}

		fileStream.close();
	}
	
}

size_t sdds::ProteinDatabase::size() const
{
	return numProtein;
}

std::string sdds::ProteinDatabase::operator[](size_t index) const
{
	string result; 

	if (index >= numProtein) {
		result =  "";		
	}
	else if (seqProtein) {
		result =  seqProtein[index];
	}
	else {
		result =  "";
	}

	return result;
}

sdds::ProteinDatabase::ProteinDatabase(const ProteinDatabase& obj)
{
	operator=(obj);
}

ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& obj) 
{
	if (this != &obj) {
		delete[] seqProtein;
		seqProtein = new std::string[obj.numProtein];
		numProtein = obj.numProtein;
		for (size_t i = 0; i < obj.numProtein; i++) {
			seqProtein[i] = obj.seqProtein[i];
		}
	}
	return *this;
}
//	Move constructor (part 2)
ProteinDatabase::ProteinDatabase(ProteinDatabase&& obj) noexcept 
{
	operator=(move(obj));
}
// move assignment operator (part 2)
ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& obj) noexcept 
{
	if (this != &obj) {

		numProtein = obj.numProtein;
		delete[] seqProtein;
		seqProtein = obj.seqProtein;
		obj.seqProtein = nullptr;
	}
	return *this;
}

sdds::ProteinDatabase::~ProteinDatabase()
{
	delete[] seqProtein;
}