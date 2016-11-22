#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include "Node.h"

class LinkedList {
public:
	Node* head;
	Node* tail;
	// Data* tempData;
	// Node* sort(Node* head);

	// Default constructor
	LinkedList();

	// Destructor
	~LinkedList();

	// Copy constructor
	LinkedList(const LinkedList& other);

	// Assignment constructor
	LinkedList& operator=(const LinkedList& other);

	// Insert a record to the linked list
	void insert(int location, int year, int month, double temperature);

	// Clear the content of this linked list
	void clear();

	friend std::ostream& operator<<(std::ostream&, const LinkedList&);

	// The functions below are written already. Do not modify them.
	void print() const;
	void print(std::ostream&) const;


	Node MergeList(Node a, Node b) {
		Node result = null;
		if (a == null)
			return b;
		if (b == null)
			return a;
		if (a.Year > b.Year) {
			result = b;
			result->next = MergeList(a, b->next);
		} else {
			result = a;
			result->next = MergeList(a->next, b);
		}
		return result;
	}


	int getLength(Node a) {
		int count = 0;
		Node h = a;
		while (h != null) {
			count++;
			h = h->next;
		}
		return count;
	}

	Node mergeSort(Node a) {
		Node oldHead = a;
		// find the length of the linkedlist
		int mid = getLength(a) / 2;
		if (a->next == null)
			return a;
		// set one pointer to the beginning of the list and another at the next
		// element after mid
		while (mid - 1 > 0) {
			oldHead = oldHead->next;
			mid--;
		}
		Node newHead = oldHead->next;// make newHead points to the beginning of
									// the second half of the list
		oldHead->next = null;// break the list
		oldHead = a;// make one pointer points at the beginning of the first
					// half of the list
		Node t1 = mergeSort(oldHead);//make recursive calls 
		Node t2 = mergeSort(newHead);
		return MergeList(t1, t2); // merge the sorted lists
	}
};

std::ostream& operator<<(std::ostream& os, const LinkedList& ll);
#endif
