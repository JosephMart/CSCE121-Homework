#ifndef NODE
#define NODE
#include <iostream>
#include "Data.h"
using namespace std;

// Include the header file for the data struct/class if you use one.
// For example, if you have a Data class in Data.h, put
//  #include "Data.h"
// below.

struct Node {
	// Add your member variable for the data fields here.
	// You can use an extra struct/class for storing the data. In that case, put
	// your definition of the data class in a separate header file, for example:
	// data.h
	// Data1 data;
	int Location;
    int Year;
    int Month;
    double tempValue;

	// Pointer to the next node in the linked list
	Node* next;

	// Default constructor
	Node() : Location(0), Year(0), Month(0), tempValue(0), next(nullptr) {}

	Node(int Location, int Year, int Month, double tempValue) : Location(Location), Year(Year), Month(Month), tempValue(tempValue), next(nullptr) {}
		
	friend std::ostream& operator<<(std::ostream& os, const Node& n) {
		os << "Location: " << n.Location << endl;
		os << "Year: " << n.Year << endl;
		os << "Month: " << n.Month << endl;
		os << "Temperature: " << n.tempValue << endl;
		return os;
	}
	// The function below is written. Do not modify it
	virtual ~Node() {}
};


#endif
