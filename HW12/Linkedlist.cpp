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
			insert(temp->data.getLocation(), temp->data.getYear(), temp->data.getMonth(), temp->data.getValue());
			temp = temp->next;
		}
	}
	return *this;
}

void LinkedList::insert(int location, int year, int month, double temperature) {
	// Implement this function
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
	os << ll.getName() << " {";
	Node* current = ll.head;
	if (current == nullptr) {
		os << " <Empty List>";
	}
	while (current != nullptr) {
		if (current != ll.head)
			cout << ",";
		cout << " " << current->value;
		current = current->next;
	}
	cout << " }";
	return os;
    
}
