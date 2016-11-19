#include "TemperatureDB.h"

#include <fstream>
#include <iostream>
using namespace std;

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function
	string line;
	ifstream myfile (filename);
	int i = 0;
	if (myfile.is_open()) {
    	while ( getline (myfile,line) ) {
			int location;
			int year;
			int month;
			double temperature;

      		records.insert(location, year, month, temperature);// << line << '\n';
			++i;
			cout << i << endl;
    	}
    	myfile.close();
  	} else
	   cout << "Unable to open file";
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function
}
