
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

#include "Station.h"
#include "LineManager.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;

	LineManager::LineManager() {
		m_cntCustomerOrder = 0;
		m_firstStation = nullptr;
	};

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		Utilities util;
		ifstream file_opened(file);
		if (file_opened.is_open()) {
			std::string line, first_workStation, second_WorkStation;
			size_t next_pos = 0;
			bool more = true;
			vector<bool> flag(stations.size(), false);

			while (getline(file_opened, line, '\n')) {

				first_workStation = util.extractToken(line, next_pos, more);

				if (!more) {
					m_activeLine.push_back(nullptr);
					auto it = std::find_if(stations.begin(), stations.end(), [=](const Workstation* ws) {
						return ws->getItemName() == first_workStation;
						});
					(*it)->setNextStation(nullptr);
				}
				else {
					std::string second_WorkStation = util.extractToken(line, next_pos, more);

					auto it1 = std::find_if(stations.begin(), stations.end(), [=](const Workstation* ws) {
						return ws->getItemName() == first_workStation;
						});
					auto it2 = std::find_if(stations.begin(), stations.end(), [=](const Workstation* ws) {
						return ws->getItemName() == second_WorkStation;
						});
					(*it1)->setNextStation(*it2);
					m_activeLine.push_back(*it2);
					flag[std::distance(stations.begin(), it2)] = true;
				}
			}
			//close file after readed 
			file_opened.close();

			auto it = std::find_if(flag.begin(), flag.end(), [](bool b) {
				return b == false;
				});
			if (it != flag.end()) {
				m_firstStation = stations[std::distance(flag.begin(), it)];
			}
			m_cntCustomerOrder = g_pending.size();
		}
	};

	void LineManager::reorderStations() {
		Workstation* currentStation = m_firstStation;
		for (size_t i = 0; i < m_activeLine.size() - 1; i++) {
			currentStation = currentStation->getNextStation();
			int id = -1;
			for (size_t j = i + 1; j < m_activeLine.size(); j++) {
				if (m_activeLine[j] == currentStation) {
					id = j;
					break;
				}
			}
			if (id != -1) {
				Workstation* temp = m_activeLine[i];
				m_activeLine[i] = m_activeLine[id];
				m_activeLine[id] = temp;
			}
		}
	};

	bool LineManager::run(std::ostream& ostr) {
		static size_t count = 0;

		count++;

		ostr << "Line Manager Iteration: " << count << endl;
		if (!g_pending.empty()) {
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}
	
		Workstation* currentStation = m_firstStation;
		while (currentStation != nullptr) {
			currentStation->fill(ostr);
			currentStation = currentStation->getNextStation();
		}
		currentStation = m_firstStation;
		while (currentStation != nullptr) {
			currentStation->attemptToMoveOrder();
			currentStation = currentStation->getNextStation();
		}
		return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());
	};

	void LineManager::display(std::ostream& ostr) const {

		for (auto activeStation : m_activeLine) {
			Workstation* currentStation = m_firstStation;
			while (currentStation != nullptr) {
				if (currentStation->getNextStation() == activeStation) {
					break;
				}
				currentStation = currentStation->getNextStation();
			}

			if (activeStation == nullptr) {
				ostr << currentStation->getItemName() 
					<< " --> End of Line" 
					<< endl;
			}
			else {
				ostr << currentStation->getItemName() << 
					" --> " << activeStation->getItemName() << endl;
			}
		}
	};













}