#include "Temperaturedb.h"
#include <fstream>
#include <iostream>
#include <typeinfo>
using namespace std;

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function
	string line;
	ifstream myfile (filename);
	int i = 0;
	int location;
	int year;
	int month;
	double temperature;
	if (myfile.is_open()) {

    	while ( myfile >> line ) {

			if(i == 0) {
				location = atoi(line.c_str());
				++i;
			} else if (i == 1) {
				year =  atoi(line.c_str());
				++i;
			} else if (i == 2) {
				month =  atoi(line.c_str());
				++i;
			} else if (i == 3) {
				temperature =  atof(line.c_str());
				if(temperature > 50 || temperature < -50) {
					// cout << "error" << endl;
				}
				records.insert(location, year, month, temperature);
				i = 0;
				
			} // else throw error

    	}
		//cout << records << endl;
    	myfile.close();
		records.head = records.sort(records.head);
		cout << records << endl;
  	} else
	   cout << "Unable to open file";
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function
}
