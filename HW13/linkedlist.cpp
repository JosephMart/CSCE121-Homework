#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
	clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	this->head = nullptr;
	this->tail = nullptr;
	Node* temp = source.head;
	while (temp) {
		this->insert(temp->data);
		temp = temp->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if (this != &source) { // Check for self-assignment, like: a = a;
		this->clear();

		// Allocate new memory & Copy data from source
		const Node* temp = source.head;
		while (temp) {
			this->insert(temp->data);
			temp = temp->next;
		}
	}
	return *this;
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

	if (q.year0 < 1800 || q.year0 > 2016 || q.year1 < 1800 || q.year1 > 2016 || q.location == 0 || q.avgMode == "") {
		return false;
	}


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
		int max_count =1;
    	int max_value = 1773;

		while (pNode != nullptr && pNode->next != nullptr) {

			bool test1 = ((pNode->data.location == q.location && pNode->data.year >= q.year0 && pNode->data.year <= q.year1));

			bool test2 = (pNode->next->data.location == q.location && pNode->next->data.year >= q.year0 && pNode->next->data.year <= q.year1);

			if (test1 && test2) {

				int currTemp = ((pNode->data.temperature) - floor((pNode->data.temperature)) <.5) ? floor((pNode->data.temperature)) : ceil(pNode->data.temperature);

				int currTemp1 = ((pNode->next->data.temperature) - floor((pNode->next->data.temperature)) <.5) ? floor((pNode->next->data.temperature)) : ceil(pNode->next->data.temperature);

				if(currTemp == currTemp1) {
					count++;
		            if(max_count<count) {
		                max_count = count;
		                max_value = currTemp;
		            }
		        } else {
		            count = 1;
		        }
			}
			pNode = pNode->next;
		}
		q.tempAvg = max_value;
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
