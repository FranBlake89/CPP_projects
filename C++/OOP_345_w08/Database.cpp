
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
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <memory>

#include "Database.h"
//using namespace std;

namespace sdds {
	std::shared_ptr<Database> Database::db = nullptr;
	
	Database::Database(const std::string& filename) : m_size_db(0), m_db_name(filename)
	{
		
			std::cout << "[" <<this<<"]"<< " Database(const std::string&)"<< std::endl;
			std::ifstream input_file(filename);
			std::string line;
			if (!input_file) {
				std::cout << "Error: open file [" << filename << "]" << std::endl;
			}
			while (std::getline(input_file, line)) {
				size_t pos = line.find(' ');
				std::string key = line.substr(0, pos);
				std::string value = line.substr(pos + 1);
				std::replace(key.begin(), key.end(), '_', ' ');
				value = trim(value);
				SetValue(key, value);
			}
			input_file.close();
		
	}
	std::shared_ptr<Database> Database::getInstance(const std::string& fileName)
	{
		std::string name;
		name = fileName;
		//db;
		if (db.get() == nullptr) {
			db = std::shared_ptr<Database>( new Database(name) );
			//return static attribute
		}
		else {
			//db exists 
			//nothing happens
		}
		return db;
	}
	Err_Status Database::GetValue(const std::string& key, std::string& value)
	{
		size_t len = m_keys->length();
		
		for (size_t i = 0; i < len; i++)
		{
			if (m_keys[i] == key) {
				//key found
		 value = m_values[i];
				return Err_Status::Err_Success;
			}
		}
		return Err_Status::Err_NotFound;

	}
	Err_Status Database::SetValue(const std::string& key, const std::string& value)
	{
		if (m_size_db <= 20) {
			m_keys[m_size_db] = key;
			m_values[m_size_db] = value;
			m_size_db++;
			return Err_Status::Err_Success;
		}
		else {
			return Err_Status::Err_OutOfMemory;
		}

	}
	Database::~Database()
	{
		std::cout << "[" << this << "]" << " ~Database()" << std::endl;
		std::string backup_filename = m_db_name + ".bkp.txt";
		std::ofstream backup_file(backup_filename);
		//backup
		if (backup_file) {
			// Iterate to backup file
			for (int i = 0; i < m_size_db; i++) {
				backup_file << std::left << std::setw(25) << m_keys[i] << " -> " << m_values[i] << std::endl;
			}
			//std::cout << "Database backup : " << backup_filename << std::endl;
		}
		else {
			//std::cout << "Error backup : " << backup_filename << std::endl;
		}
	}
	std::string trim(const std::string& str)
	{
		int first_No_blank{}, last_No_blank{};
		size_t length{};
		std::string temp{};

		if (!str.empty())
			temp = str;

		first_No_blank = temp.find_first_not_of(' ');
		last_No_blank = temp.find_last_not_of(' ');
		length = temp.length();

		if (temp.front() == ' ')
			temp.erase(0, first_No_blank);

		if (temp.back() == ' ')
			temp.erase((last_No_blank), (length));

		return temp;
	}
}