//FRANCISCO CASTILLO
//FCASTILLO-ROJAS1@MYSENECA.CA
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>

using namespace std;

namespace sdds {

class Numbers {
	double* m_numbers;
	char* m_filename;
	bool m_isOriginal;
	int m_numCount;

	bool isEmpty()const;
	void setEmpty();
	void setFilename(const char* filename);
	int numberCount();
	bool load();
	void save();
	void deallocate();

	public:
		operator bool()const;
		//~~~~~~~FIXED it :)!!!
		Numbers operator+()const;
		Numbers operator-()const;
		//-*-*-*-*-*-*-*-*-*-*-*-*-*-*
		~Numbers();
		// max() method
		double max()const; // returns the maximum value in m_numbers
		// min() method
		double min()const;
		double average()const;
		Numbers();
		Numbers(const char* filename);
		Numbers(const Numbers&);
		Numbers& operator=(const Numbers& src);
		Numbers& operator+=(const double number);
		ostream& display(ostream& ostr) const;
		Numbers& sort(bool ascending);
		friend ostream& operator<<(ostream& os, const Numbers& N);
		friend istream& operator>>(istream& istr, Numbers& N);
   };

}
#endif // !SDDS_NUMBERS_H_

