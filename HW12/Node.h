#ifndef NODE
#define NODE
#include "Data.h"

// Include the header file for the data struct/class if you use one.
// For example, if you have a Data class in Data.h, put
//  #include "Data.h"
// below.

struct Node {
	// Add your member variable for the data fields here.
	// You can use an extra struct/class for storing the data. In that case, put
	// your definition of the data class in a separate header file, for example:
	// data.h
	Data1 data;

	// Pointer to the next node in the linked list
	Node* next;

	// Default constructor
	Node() : next(nullptr) {
		// Initialize your data members properly inside the function body
		data.setLocation(0);
		data.setYear(0);
		data.setMonth(0);
		data.setValue(0);
	}

	Node(Data dataEntry) : next(nullptr) {
		// Initialize your data members properly inside the function body
		data.setLocation(dataEntry.getLocation());
		data.setYear(dataEntry.getYear());
		data.setMonth(dataEntry.getMonth());
		data.setValue(dataEntry.getValue());
	}
};

#endif
