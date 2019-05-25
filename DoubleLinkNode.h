#include "BaseNode.h"
#ifndef DOUBLELINKNODE_H
#define DOUBLELINKNODE_H

class DoubleLinkNode : public BaseNode
{
private:
	DoubleLinkNode *next;	// To point to the next node in the list
	DoubleLinkNode *prev;	// To point to the previous node in the list

public:
	// Default constructor
	DoubleLinkNode() : BaseNode()
	{
		// Set next and prev to nullptr
		next = nullptr;
		prev = nullptr;
	}

	// Overloaded constructor
	DoubleLinkNode(string r, int a, DoubleLinkNode *n, DoubleLinkNode *p) : BaseNode(r, a)
	{
		next = n;
		prev = p;
	}

	// Copy constructor
	DoubleLinkNode(const DoubleLinkNode &obj) : BaseNode(obj)
	{
		// Set next and prev pointers to the next and prev pointers of the object passed in
		next = obj.next;
		prev = obj.prev;
	}

	// Accessors
	DoubleLinkNode *getNext() const { return next; }
	DoubleLinkNode *getPrev() const { return prev; }

	// Mutators
	void setNext(DoubleLinkNode *n) { next = n; }
	void setPrev(DoubleLinkNode *p) { prev = p; }

	// Overriden virtual function
	virtual int getArabic() const { return arabic; }
};
#endif
