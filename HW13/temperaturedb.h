#ifndef TEMP_DB
#define TEMP_DB

#include "linkedlist.h"
#include <string>

class TemperatureDatabase {
public:
	// Default constructor/destructor. Modify them if you need to.
	TemperatureDatabase() {}
	~TemperatureDatabase() {}

	// The two functions below are required

	// Read the temperature records from the data file and populate the linked list
	void loadData(const string& data_file);

	// Read the queries from the query file and perform a series of queries
	void performQuery(const string& query_filename);

private:
	// Linked list to store the temperature records. You need to properly populate
	// this link list.
	LinkedList records;

	// You can add any private member variables/functions you feel useful in this class.
	const int FIRST_YEAR = 1800;
	const int CURRENT_YEAR = 2016;

	// Helper function to check if a record is valid
	bool isValidEntry(const Data& d);
	bool isValidYear(int year);
	bool isValidMonth(int month);
	bool isValidTemperature(double temperature);
	bool isMissingDataTemperature(double temperature);
};

#endif  // TEMP_DB
