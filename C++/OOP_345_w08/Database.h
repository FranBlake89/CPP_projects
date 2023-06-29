
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


#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

//using namespace std;

namespace sdds {
	enum class Err_Status
	{
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	class Database
	{
	private:
		int m_size_db{};
		std::string m_keys[20];
		std::string m_values[20];
		std::string m_db_name{};

		static std::shared_ptr <Database> db;

		Database(const std::string& fileName);

	public:
		static std::shared_ptr<Database> getInstance(const std::string& fileName);
		Err_Status GetValue(const std::string& key, std::string& value);
		Err_Status SetValue(const std::string& key, const std::string& value);
		~Database();

	};

	//helper
	std::string trim(const std::string& str);
}

