//FRANCISCO CASTILLO
//FCASTILLO-ROJAS1@MYSENECA.CA
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Numbers.h"


using namespace std;
namespace sdds {
	Numbers* numbers;

	Numbers::Numbers() {
		setEmpty();
		m_isOriginal = false;
	}

	Numbers::Numbers(const char* filename) {
		setEmpty();
		m_isOriginal = true;
		setFilename(filename);
		
		m_numCount = numberCount();
		if (m_numCount == 0 || !load()) {
			deallocate();
			setEmpty();
			m_isOriginal = false;
		}
	}
	void Numbers::deallocate() {
		delete[] m_filename;
		delete[] m_numbers;
	}
	//Copy constructor
	Numbers::Numbers(const Numbers& src)
	{
		setEmpty();
		m_isOriginal = false;
		operator=(src);
	}
	Numbers::operator bool() const {
		return m_numbers != nullptr;
	}
	//Copy assignment operator
	Numbers& Numbers::operator=(const Numbers& src)
	{
		if ((src) && (this != &src)) {
			// deletes the current collection of numbers
			delete[] m_numbers;
			delete[] m_filename;
			//set the object to the safe empty state
			Numbers::setEmpty();
			//sets the object not to be original
			m_isOriginal = false;
			m_numCount = src.m_numCount;

			m_numbers = new double[m_numCount];

			setFilename(src.m_filename);
			// copies the values in other.m_numbers to m_numbers
			for (int i = 0; i < m_numCount; i++) {
				m_numbers[i] = src.m_numbers[i];
			}
		}
		return *this;

	}
	//operator+= overload
	Numbers& Numbers::operator+=(const double number)
	{
		if (!isEmpty())
		{
			double* local = nullptr; 
			local = new double[m_numCount + 1]; 

			for (int i = 0; i < m_numCount; i++) { 
				local[i] = m_numbers[i]; 
			}
			
			local[m_numCount] = number;
			m_numCount += 1; 
			delete[] m_numbers;
			m_numbers = local; 

		}
		return *this;
	}
	std::ostream& Numbers::display(std::ostream& ostr) const
	{
		if (isEmpty())
		{
			cout << "Empty list";
		}
		else
		{
			ostr << "=========================" << endl;
			if (m_isOriginal)
			{
				ostr << m_filename << endl;
			}
			else
			{
				ostr << "*** COPY ***" << endl;
			}
			for (int i = 0; i < m_numCount - 1; i++)
			{
				ostr << std::fixed;
				ostr << std::setprecision(2);
				ostr << m_numbers[i] << ", ";
			}
	
			ostr << m_numbers[m_numCount - 1] << endl;
			ostr << "-------------------------" << endl;
			ostr << "Total of " << m_numCount << " number(s)" << endl;
			ostr << "Largest number:  " << max() << endl;
			ostr << "Smallest number: " << min() << endl;
			ostr << "Average:         " << average() << endl;
			ostr << "=========================";
		}

		return ostr;
	}

	Numbers::~Numbers() {
		save();
		deallocate();
	}
	bool Numbers::isEmpty() const {
		return m_numbers == nullptr;
	}
	void Numbers::setEmpty() {
		m_numbers = nullptr;
		m_filename = nullptr;
		m_numCount = 0;
	}
	void Numbers::setFilename(const char* filename) {
			delete[] m_filename;
			m_filename = new char[strlen(filename) + 1];
			strcpy(m_filename, filename);
			
	}
	Numbers& Numbers::sort(bool ascending) {
		
		int i, j;
		double temp;
		
		if (ascending) {
			for (i = m_numCount - 1; i > 0; i--) {
				for (j = 0; j < i; j++) {
					if (m_numbers[j] > m_numbers[j + 1]) {
						temp = m_numbers[j];
						m_numbers[j] = m_numbers[j + 1];
						m_numbers[j + 1] = temp;
					}
				}
			}
		}
		else {
			for (i = m_numCount - 1; i > 0; i--) {
				for (j = 0; j < i; j++) {
					if (m_numbers[j] < m_numbers[j + 1]) {
						temp = m_numbers[j];
						m_numbers[j] = m_numbers[j + 1];
						m_numbers[j + 1] = temp;
					}
				}
			}
		}
		return *this;
	}
	int sdds::Numbers::numberCount()
	{
		m_numCount = 0;
		std::string line;
		ifstream filein(m_filename);
		if (filein.is_open()) {
			while (std::getline(filein, line))
			{
				m_numCount++;
			}
		}
		filein.close();
		return m_numCount;
	}
	bool sdds::Numbers::load()
	{
		bool ok = false;
		ifstream file(this->m_filename);
		if (file) {
			m_numbers = new double[(m_numCount)];
			for (int i = 0; i < m_numCount; i++) {
				file >> m_numbers[i];
			}
			ok = true;
		}
		file.close();
		return ok;
		/*bool load = false;
		int rows = 0;
		if (this->m_numCount > 0)
		{
			this->m_numbers = new double[(this->m_numCount)];
			ifstream filein(this->m_filename);
			string line;

			while (!filein.fail() && rows < this->m_numCount)
			{
				filein >> this->m_numbers[rows];
				rows++;
			}
			filein.close();
		}
		if (rows == this->m_numCount)
		{
			load = true;
		}

		return load;*/
	}
	void sdds::Numbers::save()
	{
		if (m_isOriginal && !isEmpty())
		{
			ofstream ofs; 
			ofs.open(m_filename); 
			for (int i = 0; i < m_numCount; i++) {
				ofs << std::fixed;
				ofs << std::setprecision(2);
				ofs << m_numbers[i] << endl; 
			}
			ofs.close();

		}
	}
	double Numbers::average() const {
		double aver = 0.0;
		if (!isEmpty()) {
			for (int i = 0; i < m_numCount; i++)
				aver += m_numbers[i];
			aver = aver / m_numCount;
		}
		return aver;
	}

	double Numbers::min() const {
		double minVal = 0.0;
		if (!isEmpty()) {
			minVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (minVal > m_numbers[i]) minVal = m_numbers[i];
		}
		return minVal;
	}
	double Numbers::max() const {
		double maxVal = 0.0;
		if (!isEmpty()) {
			maxVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
		}
		return maxVal;
	}
	std::ostream& operator<<(std::ostream& os, const Numbers& N)
	{
		return N.display(os);
	}
	std::istream& operator>>(std::istream& istr, Numbers& N)
	{
		double d = 0.0;
		istr >> d;
		N += d;
		return istr;
	}
	Numbers Numbers::operator+() const {
		
		Numbers sum = Numbers();
		
		if ((this) && (strlen(this->m_filename) > 3)) {
			sum = *this;
			sum.sort(true);
		}	
		return sum;
	}
	Numbers Numbers::operator-()const {
		Numbers res = Numbers();

		if ((this) && (strlen(this->m_filename) > 3)) {
			res = *this;
			res.sort(false);
		}	
		return res;
	}
}