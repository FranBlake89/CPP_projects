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

#include "TimedTask.h"

using namespace std;

namespace sdds {


sdds::TimedTask::TimedTask() : m_records(0)
{
	//default constructor
}

void sdds::TimedTask::startClock()
{
	m_start_time = std::chrono::steady_clock::now();
}

void sdds::TimedTask::stopClock()
{
	m_end_time = std::chrono::steady_clock::now();
	/*
	
	arrTask[m_records].s_duration = m_end_time - m_start_time;
	m_records++;
	*/

}

void sdds::TimedTask::addTask(const char* name)
{
	size_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end_time - m_start_time).count();
	arrTask[m_records].s_name = std::string(name);
	arrTask[m_records].s_unit_time = " nanoseconds";
	arrTask[m_records].s_duration = std::chrono::nanoseconds(duration);
	m_records++;

}

ostream& operator<<(ostream& os, const sdds::TimedTask& obj)
{
    os << "--------------------------\n";
    os << "Execution Times:\n";
    os << "--------------------------\n";

    for (int i = 0; i < obj.m_records; i++)
    {
        os << left << setw(21) << obj.arrTask[i].s_name << " ";
        os << right << fixed << setprecision(0) << setw(13) << obj.arrTask[i].s_duration.count();
        os << " " << obj.arrTask[i].s_unit_time << endl;
    }
    os << "--------------------------\n";
    return os;
}


}