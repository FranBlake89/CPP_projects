/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/

#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H_
#include <ostream>
#include <iostream>
#include "Menu.h"
#include "Utils.h"
#include "Vehicle.h"

using namespace std;
namespace sdds
{
	const int MAX_SPOTS = 100;
	
	class Parking
	{
	private:
		char* m_filename = {};
		Menu m_parkingMenu;
		Menu m_vehicleMenu;
//- MS6 -------------------------------------------------------		
		/*NUMBER OF SPOTS
*Add an integer property to the Parking class for the Number 
*of Spots. This value is always less than or equal to the 
*Maximum Number of Parking Spots constant value.
		*/
		int m_numSpots = 0;
//*************************************************************
		/*PARKING SPOTS
*Create an array of Vehicle pointers that act like the Parking 
*Spots in the Parking.Use the Maximum Number of Parking Spots 
*constant value for the size of the array. 
*/
		Vehicle* m_arrParking[MAX_SPOTS];
//*************************************************************
		/*NUMBER OF PARKED VEHICLES
*Add an integer property to the Parking for the Number of Parked 
*Vehicles in the Parking. This value is always less than the 
*Number of Spots Property.	
*/
		int m_vehParked = 0; // m_vehParked < MAX_SPOTS
//*************************************************************
		void setfileName(const char* file);
		void setEmpty();
		bool isEmpty()const;
		void statusParking();
		void parkVehicle();
		void returnVehicle();
		void ListVehicles();
		void findVehicle();
		bool closeParking();
		bool exitApp();
		bool loadData();
		void saveData();
	public:
		Parking();
		Parking(const char* file);
//- MS6 ----------------------------------
/*Add an integer (noOfSpots) argument added the Parking 
*constructor. Set the value of the Number of Spots in the 
*Parking to this value. This is the maximum number of 
*Vehicles the Parking can accept. If this number is invalid 
*(less than 10 or more than the Maximum Number of Parking Spots 
*constant value) then the Parking is set as an Invalid Empty State.
*Also, make sure that all the elements of the Parking Spots array 
*are initialized to nullptr.		
*/
		Parking(const char* datafile, int noOfSpots);
/*****************************************/
		~Parking();
		Parking& operator=(const Parking&) = delete;
		int run();
	};
}
#endif // !SDDS_PARKING_H_