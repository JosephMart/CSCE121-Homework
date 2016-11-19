#include <iostream>
#include <string>
#include "Linkedlist.h"
using namespace std;

LinkedList::LinkedList() {
	// Implement this function
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList() {
	// Implement this function
	this->clear();
}

LinkedList::LinkedList(const LinkedList& other) {
    head = nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if (this != &source) { // Check for self-assignment, like: a = a;
		this->clear();

		// Allocate new memory & Copy data from source
		const Node* temp = source.head;
		while (temp) {
			insert(temp->Location, temp->Year, temp->Month, temp->tempValue);
			temp = temp->next;
		}
	}
	return *this;
}

void LinkedList::insert(int location, int year, int month, double temperature) {
	// Implement this function
	// Data1 dataTemp = Data1(location, year, month, temperature);
	Node* n = new Node(location, year, month, temperature);
	n->next = head;
	head = n;
}

void LinkedList::clear() {
	// Implement this function
	Node* current = head;
	while (current != nullptr) {
		Node* deleteNode = current;
		current = current->next;
		delete deleteNode;
	}
	head = nullptr;
        tail = nullptr;
}

void LinkedList::print() const {
	/* Do not modify this function */
	print(cout);
}

void LinkedList::print(ostream& os) const {
	/* Do not modify this function */
	os << *this;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	Node* current = ll.head;
	if (current == nullptr) {
		os << " <Empty List>";
	}
	while (current != nullptr) {
		// if (current != ll.head) {
			os << "Location: " << current->Location << endl;
			os << "Year: " << current->Year << endl;
			os << "Month: " << current->Month << endl;
			os << "Temperature: " << current->tempValue << endl;
			os << endl;
			current = current->next;
		// }
	}
	return os;
}
