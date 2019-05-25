#include "DoubleLinkNode.h"
#include <fstream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
private:
	DoubleLinkNode *head;	// Head pointer
	DoubleLinkNode *tail;	// Tail pointer

public:
	// Default constructor
	LinkedList()
	{
		// Set head and tail to nullptr
		head = nullptr;
		tail = nullptr;
	}

	// Overloaded constructor
	LinkedList(DoubleLinkNode *h) { head = h; }
	
	// Accessors
	DoubleLinkNode * getHead() const { return head; }
	DoubleLinkNode * getTail() const { return tail; }

	// Mutators
	void setHead(DoubleLinkNode *h) { head = h; }
	void setTail(DoubleLinkNode *t) { tail = t; }

	// Print function
	void printList(ofstream &, DoubleLinkNode *);

	// Destructor
	~LinkedList();

	// Overloaded operator functions
	void operator+= (DoubleLinkNode *);
	LinkedList& operator-- ();		// prefix decrementor
	LinkedList& operator-- (int);	// postfix decrementor

};
#endif