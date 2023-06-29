/*
   ---------------------------------------
Name:		Francisco Castillo
Seneca Id:	148904212
e-mail:		fcastillo-rojas1@myseneca.ca
Section:	NDD
   ---------------------------------------
*/
#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

namespace sdds {
	const int MAX_SIZE = 10;
	//Struct
	struct Task {
		string s_name{};
		string s_unit_time{};
		std::chrono::steady_clock::duration s_duration{};
	};
	//Classes
	class TimedTask
	{
	protected:
		int m_records{};
		std::chrono::steady_clock::time_point m_start_time{};
		std::chrono::steady_clock::time_point m_end_time{};
		Task arrTask[MAX_SIZE]{};
	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* name);
		friend ostream& operator<<(ostream& os, const TimedTask& obj);
	};

}

