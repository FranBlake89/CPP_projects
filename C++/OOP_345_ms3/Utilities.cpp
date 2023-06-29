/*
> Name: Francisco Castillo
> Course: OOP
> Section: NDD
> Seneca ID: 148904212
> Seneca email: fcastillo-rojas1@myseneca.ca
> Date of completion: 2023-mm-dd

* I confirm that I am the only author of this file
 and the content was created entirely by me.
*/

#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;
namespace sdds
{
	static char m_delimiter;
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	};

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	};

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string temp;
		size_t end_pos = str.find_first_of(m_delimiter, next_pos);
		if (str[next_pos] == m_delimiter) {
			more = false;
			throw invalid_argument("ERROR: No token.");
		}
		else {
			if (str.find(m_delimiter, next_pos) == std::string::npos) {
				temp = str.substr(next_pos);
				temp.erase(0, temp.find_first_not_of(" "));
				more = false;
				next_pos = 0;
			}
			else {
				temp = str.substr(next_pos, end_pos - next_pos);
				temp.erase(0, temp.find_first_not_of(" "));
				end_pos = temp.find_last_not_of(" ");
				if ((end_pos + 1) != std::string::npos) {
					temp.erase(end_pos + 1);
				}
				next_pos = str.find(m_delimiter, next_pos) + 1;
				more = true;

			}
		}

		if (m_widthField < temp.length()) {
			m_widthField = temp.length();
		}
		return temp;
	};

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	};

	char Utilities::getDelimiter() {
		return m_delimiter;
	};


}