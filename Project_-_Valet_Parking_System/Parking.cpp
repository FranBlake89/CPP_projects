/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <algorithm>

#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;

namespace sdds {
	Parking::Parking(const char* datafile, int noOfSpots) :
		m_filename(nullptr),
		m_parkingMenu("Parking Menu, select an action:"),
		m_vehicleMenu("Select type of the vehicle:", 1)
		{
			int i;
			for (i = 0; i < MAX_SPOTS; i++)
			{
				m_arrParking[i] = nullptr;
			}
			m_vehParked = 0;

			// if parameter datafile and noOfSpots is valid, allocate memory, copy string, and set numSpots
			if (datafile != nullptr && datafile[0] != '\0' && !(noOfSpots < 10 || noOfSpots > MAX_SPOTS))
			{
				unsigned int i; 
				unsigned int size;
				size = unsigned(strlen(datafile));
				m_filename = new char[size + 1];
				for (i = 0; i < size; i++)
				{
					m_filename[i] = datafile[i];
				}
				m_filename[size] = '\0';

				m_numSpots = noOfSpots;
			}
			else
			{
				m_numSpots = 0;
			}

			if (loadData())
			{
				// add to parking menu 6 items
				m_parkingMenu << "Park Vehicle"
					<< "Return Vehicle"
					<< "List Parked Vehicles"
					<< "Find Vehicle"
					<< "Close Parking (End of day)"
					<< "Exit Program";
				//add to vehicle menu 3 items
				m_vehicleMenu << "Car"
					<< "Motorcycle"
					<< "Cancel";
			}
			else
			{
				// display error message and set empty state
				cout << "Error in data file" << endl;
				setEmpty();
			}
	}
	void Parking::setfileName(const char* file)
	{
		m_filename = new char[strlen(file)+1];
		strcpy(m_filename, file);
	}
	void Parking::setEmpty()
	{
		delete[] m_filename;
		m_filename = nullptr;
	}
	bool Parking::isEmpty() const
	{
		return m_filename == nullptr;
	}
	void Parking::statusParking()
	{
		cout << "****** Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(ios::left);
		cout << m_numSpots - m_vehParked << " *****" << endl;
	}
	void Parking::parkVehicle()
	{
		if (m_vehParked < m_numSpots)
		{
			m_vehicleMenu.display();
			int i, done = 0, choice = 0;

			do
			{
				Utils::read(choice, 1, 3, "Invalid selection, try again: ");
			} while (!(choice >= 1 && choice <= 3));

			switch (choice)
			{
			case 1:
				if (m_vehParked < m_numSpots)
				{
					Vehicle* temp = new Car;
					temp->setCsv(false);
					temp->read(cin);

					for (i = 0, done = 0; i < MAX_SPOTS && done == 0; i++)
					{
						if (m_arrParking[i] == nullptr)
						{
							m_arrParking[i] = temp;
							m_arrParking[i]->setParkingSpot(i + 1);
							cout << "\nParking Ticket" << endl;
							m_arrParking[i]->write(cout);
							cout << endl;
							m_vehParked++;
							done = 1;
						}
					}
				}
				break;
			case 2:
				//cout << "Parking Motorcycle" << endl;
				if (m_vehParked < m_numSpots)
				{
					Vehicle* temp = new Motorcycle;
					temp->setCsv(false);
					temp->read(cin);

					for (i = 0, done = 0; i < m_numSpots && done == 0; i++)
					{
						if (m_arrParking[i] == nullptr)
						{
							m_arrParking[i] = temp;
							m_arrParking[i]->setParkingSpot(i + 1);
							cout << "\nParking Ticket" << endl;
							m_arrParking[i]->write(cout);
							cout << endl;
							m_vehParked++;
							done = 1;
						}
					}
				}
				break;
			case 3:
				cout << "Parking cancelled" << endl;
				break;
			}
		}
		else
		{
			cout << "Parking is full" << endl;
		}
	}
	void Parking::returnVehicle()
	{
		string licensePlate;
		string errorMessage;
		unsigned int minlen = 0, maxlen = 0, lenSTR = 0;
		bool isFound = false;
		cout << "Return Vehicle" << endl;
		cout << "Enter License Plate Number: ";
		minlen = 1;
		maxlen = 8;
		errorMessage = "Invalid License Plate, try again: ";

		do {
			cin >> licensePlate;
			lenSTR = licensePlate.length();

			if (cin.fail()) {
				cin.ignore(maxlen);
				fflush(stdin);
			}
		} while (lenSTR < unsigned(minlen) && cout << errorMessage);

		std::for_each(licensePlate.begin(), licensePlate.end(), [](char& c) {
			c = ::toupper(c);
			});

		int i;
		for (i = 0; i < m_numSpots; i++)
		{
			string temp; //will store string from record
			temp.clear();

			if (m_arrParking[i] != nullptr)
			{
				temp = m_arrParking[i]->getLicensePlate();

				if (temp == licensePlate)
				{
					isFound = true;
					cout << "\nReturning:" << endl;
					m_arrParking[i]->setCsv(false);
					m_arrParking[i]->write(cout);
					cout << endl;
					delete m_arrParking[i];
					m_arrParking[i] = nullptr;
					m_vehParked--;
					
				}
			}
		}
		if (!isFound) {
			cout << "\nLicense plate " << licensePlate << " Not found\n" << endl;
		}
		cout << "Press <ENTER> to continue....";
		cin.ignore();
		cout << endl;
	}
	void Parking::ListVehicles()
	{
		cout << "*** List of parked vehicles ***" << endl;
		int i;
		for (i = 0; i < m_numSpots; i++)
		{
			if (m_arrParking[i] != nullptr)
			{
				m_arrParking[i]->setCsv(false);
				m_arrParking[i]->write(cout);
				cout << "-------------------------------" << endl;
			}
		}
		cout << "Press <ENTER> to continue....";
		cin.ignore(1000,'\n');
		
	}
	void Parking::findVehicle()
	{
		string licensePlate;
		string errorMessage;
		unsigned int minlen, maxlen, lenSTR;
		bool isFound = false;
		cout << "Vehicle Search" << endl;
		cout << "Enter License Plate Number: ";
		//Utils::read(licensePlate, 1, 8, "Invalid License Plate, try again: ", cin);
		minlen = 1;
		maxlen = 8;
		errorMessage = "Invalid License Plate, try again: ";

		
		do {
			cin >> licensePlate;
			lenSTR = licensePlate.length();
			
			if (cin.fail()) {
				cin.ignore(maxlen);
				fflush(stdin);
			}
		} while (lenSTR < unsigned(minlen) && cout << errorMessage);
		
		std::for_each(licensePlate.begin(), licensePlate.end(), [](char& c) {
			c = ::toupper(c);
			});
		
		int i;
		for (i = 0; i < m_numSpots; i++)
		{
			string temp; //will store string from record
			temp.clear();

			if (m_arrParking[i] != nullptr)
			{
				temp= m_arrParking[i]->getLicensePlate();


				if ( temp == licensePlate )
				{
					isFound = true;
					cout << "\nVehicle found:" << endl;
					m_arrParking[i]->setCsv(false);
					m_arrParking[i]->write(cout);
					cout << endl;
					
				}
			}
		}
		if (!isFound) {
			cout << "\nLicense plate " << licensePlate << " Not found\n" << endl;
		}
		cout << "Press <ENTER> to continue....";
		cin.ignore();
		cout << endl;
	}
	bool Parking::closeParking()
	{
		bool closeParking = false;
		bool wrongChc = false;
		char res;

		cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		do
		{
			cin >> res;

			if (res == 'y' || res == 'Y')
			{
				wrongChc = false;
				closeParking = true;
				cout << "Closing Parking" << endl;
				int i;
				for (i = 0; i < m_numSpots; i++)
				{
					if (m_arrParking[i] != nullptr)
					{
						cout << "\nTowing request" << endl;
						cout << "*********************" << endl;
						m_arrParking[i]->setCsv(false);
						
						m_arrParking[i]->write(cout); //<<<<check HERE CSV, MUST BE FALSE

						delete m_arrParking[i];
						m_arrParking[i] = nullptr;
						m_vehParked--;
					}
				}
			}
			else if (res == 'n' || res == 'N')
			{
				cout << "Aborted!" << endl;
				wrongChc = false;
				closeParking = false;
			}
			else {
				cin.clear();
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				wrongChc = true;
			}
		} while (wrongChc);
		
		return closeParking;
	}
	bool Parking::exitApp()
	{
		bool exitApp = false;
		bool wrongChc = false;
		char res;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		do
		{
			cin >> res;

			if (res == 'y' || res == 'Y')
			{
				wrongChc = false;
				exitApp = true;
				cout << "Exiting program!" << endl;
				saveData();
			}
			else if (res == 'n' || res == 'N')
			{
				wrongChc = false;
				exitApp = false;
			}
			else {
				cin.clear();
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				wrongChc = true;
			}
		} while (wrongChc);

		return exitApp;
	}
	bool Parking::loadData()
	{
		bool state;
		if (!isEmpty())
		{
			// open File
			ifstream file(m_filename);
			
			if (!file)
			{
				state = true;
			}
			else
			{
				while (file.good() && m_vehParked < m_numSpots)
				{
					Vehicle* temp;
					char type = file.get();
					file.ignore();

					if (type == 'M')
					{
						temp = new Motorcycle;
						temp->setCsv(true);
						temp->read(file);
						if (!file.bad())
						{
							int spotNo = temp->getParkingSpot();
							m_arrParking[spotNo - 1] = temp;
							m_vehParked++;
						}
						else
						{
							delete temp;
						}
					}

					else if (type == 'C')
					{
						temp = new Car;
						temp->setCsv(true);
						temp->read(file);
						if (!file.bad())
						{
							int spotNo = temp->getParkingSpot();
							m_arrParking[spotNo - 1] = temp;
							m_vehParked++;
						}
						else
						{
							delete temp;
						}
					}
				}
				state = true;

			}
			file.clear();
			file.close();
			

		}
		else
		{
			state = false;
		}

		return state;
	}
	void Parking::saveData()
	{
		ofstream file(m_filename);
		file.clear();
		if (file)
		{
			int i;
			for (i = 0; i < m_numSpots; i++)
			{
				if (m_arrParking[i] != nullptr)
				{
					m_arrParking[i]->setCsv(true);
					//saving data
					m_arrParking[i]->write(file);
				}
			}
		}

		file.close();
	}
	Parking::Parking()
	{
		m_filename = nullptr;
		Menu m_parkingMenu();
		Menu m_vehicleMenu();
	}
	Parking::Parking(const char* file):
		m_filename(nullptr),
		m_parkingMenu("Parking Menu, select an action:"),
		m_vehicleMenu("Select type of the vehicle:", 1)
	{
		if (file != nullptr && file[0] !='\0')
		{
			setfileName(file);
		}
		
		if (loadData()) {
			m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
			m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
		}
		else if (!loadData()) {
			cout << "Error in data file" << endl;
			setEmpty();
		}
		

	}
	Parking::~Parking()
	{
		saveData();
		setEmpty();

		int i;
		for (i = 0; i < m_numSpots; i++)
		{
			delete m_arrParking[i];
			m_arrParking[i] = nullptr;
		}
		
	}
	int Parking::run()
	{
		const int minChc = 1;
		const int maxChc = 6;
		bool done = false;
		int choice = 0;
		while (!isEmpty() && !done)
		{
			statusParking();
			m_parkingMenu.display();
			Utils::read(choice, minChc, maxChc, "Invalid selection, try again: ");
			
			switch (choice)
			{
			case 1:
				parkVehicle();
				cout << "Press <ENTER> to continue....";
				cin.ignore(1000, '\n');
				break;
			case 2:
				returnVehicle();
				break;
			case 3:
				ListVehicles();
				break;
			case 4:
				findVehicle();
				break;
			case 5:
				done = closeParking();
				break;
			case 6:
				done = exitApp();
				break;
			default:
				break;
			}
		}

		return (isEmpty()) ? 1 : 0;
	}
}
