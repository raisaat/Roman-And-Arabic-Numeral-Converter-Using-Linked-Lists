// RAISAAT ATIFA RASHID
// Net ID: rar150430
// CS 1337.001 - Project 5

// DELETE ANY NODE

#include <iostream>
#include "LinkedList.h"
#include "DoubleLinkNode.h"
using namespace std;

// Function prototypes
void sortList(LinkedList &list);
bool binarySearch(const LinkedList& list, string str);
void deleteSpecificNode(LinkedList &list);

int main()
{
	// Open the file
	ifstream inFile("Z:\\Desktop\\numbers1.txt");

	LinkedList list;	// LinkedList object to hold the file data
	int menu;			// To hold the menu selected by the user

	// While it is not the end of the file
	while (!inFile.fail())
	{
		// Dynamically allocate a DoubleLinkNode object
		DoubleLinkNode *ptr = new DoubleLinkNode;

		// Read the file data into the DoubleLinkNode object
		inFile >> *ptr;

		// If the file data is valid and has been successfully 
		// added to the roman and arabic member variables of the DoubleLinkNode object
		if (ptr->getArabic() != 0)
			list += ptr;	// Add the object to the linked list

		// Else delete the DoubleLinkNode object
		else
			delete ptr;
	}

	sortList(list);	// Sort the linked list

	// Do while 6 is not selected
	do
	{
		// Get the menu from the user
		cout << "\nSelect what you want to do with the data:\n1. Search\n2. Add\n3. Delete first\n4. Delete last\n5. Delete specific node\n6. Exit\n";
		cin >> menu;

		// If the user enters 1
		if (menu == 1)
		{
			// To hold the numeral the user wants to search
			string numeral;
			
			// Get the numeral from the user
			cout << "Enter the numeral you want to search:\n";
			cin >> numeral;

			// Call the binarySearch function and if the value is found
			// print a message saying so
			if (binarySearch(list, numeral))
				cout << "The numeral has been found.\n";
			
			// Else print a message saying that the value has not been found
			else
				cout << "The numeral has not been found.\n";
		}

		// Else if the user enters 2
		else if (menu == 2)
		{
			// Dynamically allocate a DoubleLinkNode object
			DoubleLinkNode *ptr = new DoubleLinkNode;

			// Get the numeral the user wants to add
			cout << "Enter the numeral you want to add:\n";
			cin >> *ptr;

			// Add the DoubleLinkNode object to the linked list
			list += ptr;
			
			// Sort the list
			sortList(list);
		}

		// Else if the user enters 3, delete the first node of the linked list
		else if (menu == 3)
			--list;

		// Else if the user enters 4, delete the last node of the linked list
		else if (menu == 4)
			list--;

		// Else if the user enters 5, call the deleteSpecificNode function
		else if (menu == 5)
			deleteSpecificNode(list);

	} while (menu != 6);
	
	ofstream outFile("Z:\\Desktop\\numbersXC_output.txt");
	list.printList(outFile, list.getHead());
	outFile.close();

	return 0;
}

void sortList(LinkedList &list)
{
	DoubleLinkNode *ptr1;	// Pointer to traverse the linked list
	bool swap;				// To hold true if value is found or false otherwise

	// Do while swap is equal to true
	do
	{
		// Set swap equal to false
		swap = false;
		
		// Set ptr1 to the head of the linked list
		ptr1 = list.getHead();

		// While ptr1->getNext() is not equal to the null
		while (ptr1->getNext())
		{
			// If ptr1 is equal to the head of the list and ptr1->getArabic() > ptr1->getNext()->getArabic()
			if (ptr1 == list.getHead() && ptr1->getArabic() > ptr1->getNext()->getArabic())
			{
				// Swap the node ptr1 is pointing to with the node that comes after it
				ptr1->setPrev(ptr1->getNext());
				ptr1->setNext(ptr1->getPrev()->getNext());
				list.setHead(ptr1->getPrev());
				list.getHead()->setNext(ptr1);
				list.getHead()->setPrev(nullptr);

				// If the list does not have one node only
				if (list.getHead() != list.getTail())
					ptr1->getNext()->setPrev(ptr1);
				
				// Else if the list has only one node, set the tail of the list to ptr1
				else
					list.setTail(ptr1);
				
				// Set swap to true
				swap = true;
			}

			// Else if ptr1->getArabic() > ptr1->getNext()->getArabic()
			else if (ptr1->getArabic() > ptr1->getNext()->getArabic())
			{
				// Swap the node ptr1 is pointing to with the node that comes after it
				ptr1->getNext()->setPrev(ptr1->getPrev());
				ptr1->getPrev()->setNext(ptr1->getNext());
				ptr1->setNext(ptr1->getNext()->getNext());
				ptr1->setPrev(ptr1->getPrev()->getNext());
				ptr1->getPrev()->setNext(ptr1);

				// If ptr1 is not pointing to the last node of the list
				if (ptr1->getNext())
					ptr1->getNext()->setPrev(ptr1);

				// Else if ptr1 is pointing to the last node of the list, set the tail of the list to ptr1
				else
					list.setTail(ptr1);
				
				// Set swap to true
				swap = true;
			}

			// Else go to the next node of the list
			else
				ptr1 = ptr1->getNext();
		}
	} while (swap);
}

bool binarySearch(const LinkedList& list, string str)
{
	int num, size = 0;	// int variables to hold the numeral to be searched and the size of the list respectively
	DoubleLinkNode *first, *middle, *last;	// Pointers to point to the beginning, middle and end of the list repectively
	
	// If the user enters an Arabic numeral, 
	// convert the string to an int and assign it to num
	if (str[0] >= 48 && str[0] <= 57)
		num = atoi(str.c_str());
	
	// Else if the user enters a Roman numeral
	else
	{
		// Insert the numeral into a DoubleLinkNode object to find its arabic equivalent
		DoubleLinkNode *ptr = new DoubleLinkNode;
		ptr->setRoman(str);

		// Assign the object's arabic numeral to num
		num = ptr->getArabic();

		// delete the object
		delete ptr;
	}

	// Set first, middle and last to point to the beginning, middle and end of the list
	first = list.getHead();
	last = list.getTail();
	middle = first;

	// Get the size of the list
	while (first)	// While first is not equal to null
	{
		// Increment size
		size++;

		// Go to the next node in the list
		first = first->getNext();
	}

	// Set first back to the beginning of the list
	first = list.getHead();

	// While first and last are not equal to null and first->getArabic() <= last->getArabic()
	while (last && first && first->getArabic() <= last->getArabic())
	{
		// If the size of the list is an odd number, increment it
		if (size % 2 == 1)
			size++;
		
		// divide the size of the list by 2
		size /= 2;

		// Set middle to point to the node halfway between first and last
		for (int count = 0; count < size - 1; count++)
			middle = middle->getNext();

		// If middle is equal to null, break from the while loop
		if (!middle)
			break;

		// If the value is found return true
		if (middle->getArabic() == num)
			return true;

		// Else if middle->getArabic() > num, set last to
		// point to the node preceding the node that middle is pointing to
		else if (middle->getArabic() > num)
			last = middle->getPrev();

		// Else, set first to point to the node succeeding 
		// the node that middle is pointing to
		else
			first = middle->getNext();

		// Set middle to first
		middle = first;
	}

	// Return false
	return false;
}

void deleteSpecificNode(LinkedList &list)
{
	// Variables to hold the search value
	string str;
	int num;

	// Get the numeral the user wants to search
	cout << "Enter the value you want to delete:\n";
	cin >> str;

	// If the user enters an Arabic numeral, 
	// convert the string to an int and assign it to num
	if (str[0] >= 48 && str[0] <= 57)
		num = atoi(str.c_str());

	// Else if the user enters a Roman numeral
	else
	{
		// Insert the numeral into a DoubleLinkNode object to find its arabic equivalent
		DoubleLinkNode *ptr = new DoubleLinkNode;
		ptr->setRoman(str);

		// Assign the object's arabic numeral to num
		num = ptr->getArabic();

		// delete the object
		delete ptr;
	}

	DoubleLinkNode *ptr = list.getHead();	// Pointer to point to the beginning of the list

	// While it is not the end of the list
	while (ptr)
	{
		// If the vaule is found
		if (ptr->getArabic() == num)
		{
			// Reassign the next and prev pointers of the nodes preceding
			// and succeeding the node that ptr is pointing to
			if (ptr == list.getHead())
				list.setHead(ptr->getNext());
			if (ptr == list.getTail())
				list.setTail(ptr->getPrev());
			if (ptr->getPrev())
				ptr->getPrev()->setNext(ptr->getNext());
			if (ptr->getNext())
				ptr->getNext()->setPrev(ptr->getPrev());

			// delete the node ptr is pointing to
			delete ptr;

			// Display a success message
			cout << "Value successfully removed\n";

			// break from the loop
			break;
		}

		// Else if ptr is pointing to the last node of the list
		// display a message saying that the value was not found
		else if (ptr == list.getTail())
			cout << "Value not found.\n";

		// Go to the next node of the list
		ptr = ptr->getNext();
	}
}