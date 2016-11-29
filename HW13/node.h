#ifndef NODE_H
#define NODE_H

// Include the header file for the data struct/class if you use one.
// For example, if you have a Data class in Data.h, put
//  #include "Data.h"
// below.
#include "data.h"

#include <iostream>
using namespace std;

struct Node {
	// Add your member variable for the data fields here.
	// You can use an extra struct/class for storing the data. In that case, put
	// your definition of the data class in a separate header file, for example:
	// data.h
	Data data;

	// Pointer to the next node in the linked list
	Node* next;

	// Default constructor
	Node() : next(nullptr) {}

	Node(const Data& d) : data(d), next(nullptr) {}

	// The function blew is written already. Do not modify it.
	virtual ~Node() {}
};

ostream& operator<<(ostream& os, const Node& n);

#endif
