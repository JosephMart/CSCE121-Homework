#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
	clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function and remove the following statment
	throw runtime_error("This function is not implemented yet!");
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function and remove the following statment
	throw runtime_error("This function is not implemented yet!");
}

void LinkedList::insert(const Data& d) {
	Node* new_node = new Node(d);

	if (head == nullptr) {
		head = tail = new_node;
	} else {
		Node* ptr = head;

		if (new_node->data < ptr->data) {
			// Insert before head
			head = new_node;
			new_node->next = ptr;
		} else {
			// Move ptr and nxt together to find the insertion spot
			Node* nxt = ptr->next;
			while (nxt != nullptr) {
				if (new_node->data < nxt->data) break;
				ptr = nxt;
				nxt = nxt->next;
			}

			// Insert the new node between ptr and nxt
			ptr->next = new_node;
			new_node->next = nxt;
		}

		// Fix tail pointer if necessary
		if (tail == ptr) tail = new_node;
	}
}

void LinkedList::insert(int location, int year, int month, double temperature) {
	insert(Data(location, year, month, temperature));
}

void LinkedList::clear() {
	Node* ptr = head;
	while (ptr != nullptr) {
		Node* tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
	// Make sure head and tail are reset
	head = tail = nullptr;
}

void LinkedList::print() const {
	/* Do not modify this function */
	print(cout);
}

void LinkedList::print(ostream& os) const {
	/* Do not modify this function */
	os << *this;
}

bool LinkedList::query(Query& q) {
	Node* pNode = head;
	double temps = 0;
	int count = 0;

	if (q.avgMode == "AVG") {
		while (pNode != nullptr) {
			if (pNode->data.location == q.location && pNode->data.year >= q.year0 && pNode->data.year <= q.year1) {
				temps += pNode->data.temperature;
				count++;
			}
			pNode = pNode->next;
		}
		q.tempAvg = temps/count;
		return true;
	} else if (q.avgMode == "MODE") {
		//calculate mode

		while (pNode != nullptr) {
			if (pNode->data.year >= q.year0 && pNode->data.year <= q.year1) {
				temps += pNode->data.temperature;
				count++;
			}
			pNode = pNode->next;
		}
		q.tempAvg = temps/count;
		return true;
	} else return false;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	Node* ptr = ll.head;
	while (ptr != nullptr) {
		os << ptr->data << endl;
		ptr = ptr->next;
	}
	return os;
}
