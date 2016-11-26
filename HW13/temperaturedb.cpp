#include "temperaturedb.h"

#include <fstream>
#include <stdexcept>
#include <math.h>
#include "iostream"
using namespace std;

void TemperatureDatabase::loadData(const string& filename) {
	ifstream fin(filename);
	if(!fin) throw runtime_error("Failed to open file " + filename);

	// Structure to hold the temperary data read from the input file
	Data record;
	while (fin >> record) {
		// Check if the record is valid, and skip it if it is not valid
		bool isValid = isValidEntry(record);
		bool isMissing = isMissingDataTemperature(record.temperature);
		if(!isValid) {
			// We stop execution if the data entry is invalid
			cout << "Error: record " << record << " is invalid." << endl;
			throw runtime_error("Critical error: Invalid data entry!");
		} else if(isMissing) {
			// Missing data entry, we simply skip it
			continue;
		} else {
			// We use the helper function to insert a record directly
			// We can also write
			// records.insert(record.location, record.year, record.month, record.temperature);
			records.insert(record);
		}
	}
}

void TemperatureDatabase::performQuery(const string& filename) {
  	// Implement this function
  	ifstream fin(filename);
	if(!fin) throw runtime_error("Failed to open file " + filename);
	std::ofstream ofs ("results.dat", std::ofstream::out);
  	Query statment;

  	while (fin >> statment) {
		if (records.query(statment)) {
			ofs << statment << endl;
			// cout << statment << endl;
		}
  	}
}

bool TemperatureDatabase::isValidEntry(const Data& entry) {
	return isValidYear(entry.year)
	    && isValidMonth(entry.month)
			&& isValidTemperature(entry.temperature);
}

bool TemperatureDatabase::isValidYear(int year) {
	return year >= FIRST_YEAR && year <= CURRENT_YEAR;
}

bool TemperatureDatabase::isValidMonth(int month) {
	return month >= 1 && month <= 12;
}

bool TemperatureDatabase::isValidTemperature(double temperature) {
	return (temperature >= -50.0 && temperature <= 50.0)
			|| isMissingDataTemperature(temperature);	// Missing data is considered valid.
}

bool TemperatureDatabase::isMissingDataTemperature(double temperature) {
	// Be carefule with numerical comparison
	return fabs(temperature + 99.99) < 1e-2;
}
