#include "LinkedList.h"
#include <iostream>
using namespace std;

// Print function
void LinkedList::printList(ofstream &out, DoubleLinkNode *ptr)
{
	// If the end of the list is reached, return
	if (!ptr)
		return;

	else
	{
		// Print the contents of the node ptr is pointing to the ofstream object
		out << *ptr;

		// Set ptr to point to the next node of the list
		ptr = ptr->getNext();

		// Call the printlist function with the ofstream object and ptr as arguments
		printList(out, ptr);
	}
}

// Destructor
LinkedList::~LinkedList()
{
	// If head is pointing to null, return
	if (!head)
		return;
	else
	{
		// Set ptr to head
		DoubleLinkNode *ptr = head;

		// Set head to point to the next node in the list
		head = head->getNext();

		// Delete the node that ptr is pointing to
		delete ptr;

		// Call the destructor
		LinkedList::~LinkedList();
	}
}

// Overloaded += operator function
void LinkedList::operator+= (DoubleLinkNode *right)
{
	// If the list is empty
	if (!head)
	{
		// Set head and tail to point to the object passed in
		head = right;
		tail = right;
	}

	else
	{
		// Set the next pointer of the node that the tail is
		// pointing to, to point to the object passed in
		tail->setNext(right);

		// Set the prev pointer of the object passed in to point to the tail
		right->setPrev(tail);

		// Set tail to point to object passed in
		tail = right;
	}
}

// Overloaded prefix -- operator function
LinkedList& LinkedList::operator--()
{
	// Set ptr to head
	DoubleLinkNode *ptr = head;

	// Set head to point to the next node in the list
	head = head->getNext();

	// Set the prev pointer of the node that the head is pointing
	// to, to nullptr
	head->setPrev(nullptr);

	// Delete the node that ptr is pointing to
	delete ptr;

	return *this;
}

// Overloaded postfix -- operator function
LinkedList& LinkedList::operator-- (int)
{
	// Set ptr to tail
	DoubleLinkNode *ptr = tail;

	// Set tail to point to the previous node in the list
	tail = tail->getPrev();

	// Set the next pointer of the node that the tail is pointing
	// to, to nullptr
	tail->setNext(nullptr);

	// Delete the node that ptr is pointing to
	delete ptr;	

	return *this;
}