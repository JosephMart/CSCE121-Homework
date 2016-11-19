#include "Temperaturedb.h"

#include <fstream>
#include <iostream>
using namespace std;

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function
	string line;
	ifstream myfile (filename);
	int i = 0;
	if (myfile.is_open()) {
    	while ( myfile >> line ) {
			int location;
			int year;
			int month;
			double temperature;
			
			if(i == 0) {
				location = atoi(line.c_str());
				++i;
			} else if (i == 1) {
				year =  atoi(line.c_str());
				++i;
			} else if (i == 2) {
				month ==  atoi(line.c_str());
				++i;
			} else if (i == 3) {
				temperature =  atoi(line.c_str());
				i = 0;
			} // else throw error
			
      		records.insert(location, year, month, temperature);// << line << '\n';
			cout << i << endl;
    	}
    	myfile.close();
  	} else
	   cout << "Unable to open file";
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function
}
