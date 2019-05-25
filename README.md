# Roman-And-Arabic-Numeral-Converter-Using-Linked-Lists

A program that reads data from a file and converts the Roman numerals in it to Arabic numerals and vice-versa. Implements doubly-linked lists and other data structures. Contains multiple classes - abstract and non-abstract. Uses binary search and bubble sort on the linked lists to search user-entered numerals. Contains overloaded operator functions that allow the user to add or delete nodes from the linked list.


### Program Details

The program reads a file containing Roman and Arabic numerals and converts them to the missing type, i.e. the Roman numerals to Arabic and vice-versa. All numbers range from 1 - 4999. It stores the file contents in a doubly-linked list and performs all the data manipulation in the linked list. At the end of the program, it writes the contents of the linked list back to the file.


**File Structure:**

The file may contain an unknown quantity of numbers to convert, and each number will be on a separate line. The number can be either Arabic or Roman. Each line of the file will have the same format: \<Roman numeral field\>\<space\>\<Arabic numeral field\>\<new line\>. The Roman numeral field is 15 characters long and the Arabic numeral field is 4 characters long. Only one of the fields will hold a value on each line. If a field does not hold a value, it will contain all spaces. The last line will not have a new line at the end. 

The file may contain invalid data. If invalid data is identified, the file entry is ignored. Invalid data include: 1) Arabic numeral outside the given range, 2) Invalid characters in Roman numeral, and 3) Invalid characters in Arabic numeral.


**Data Manipulation:**

After all the data is read from the file, the data is bubble-sorted in ascending order (smallest to largest value for Arabic numerals and alphabetically for Roman numerals). Sorting is done by moving the nodes NOT by exchanging node data.

The user is able to search the data. The user may type in an Arabic or Roman numeral, while searching the data. A binary search is used to find the numeral.

The user is able to add and delete data. This is done by adding/deleting data from the list. When data is added, a node is added to the end of the list and the numeral typed in by the user that is to be added maybe Arabic or Roman. The user input is converted to the opposite type and both values (Arabic and Roman) are stored in the node, and the node is added to the end of the list. The linked list is sorted after the node is added. The user may delete data from the beginning or end of the list or a delete a specific node. To delete a specific node, the user is prompted to type in the value to delete. The numeral maybe Arabic or Roman. The value is then searched and if the value is found, it is removed from the list and a success message is displayed. If the value is not found, an error message is displayed.

A simple menu interface is displayed that allows the user to search and sort the data. The menu consists of 6 options:

1. Search
2. Add
3. Delete first
4. Delete last
5. Delete specific node
6. Exit

All user input is assumed to be valid, but the file contents may be invalid.


### Class Details

**BaseNode:**
* Abstract class
* Attributes:
  * Roman Numeral
  * Arabic Numeral
* Methods:
  * Default Constructor
  * Overloaded Constructor
  * Copy Constructor
  * Accessors
  * Mutators
  * Overloaded <<
    * Outputs a single node using the specified file format
  * Overloaded >>
    * Add node
  * ConvertToRoman
    * Converts an Arabic numeral to a Roman numeral
  * ConvertToArabic
    * Converts a Roman numeral to an Arabic numeral

**DoubleLinkNode:**
* Derived from BaseNode
* Attributes:
  * Next Pointer
  * Prev Pointer
* Methods:
  * Default Constructor
  * Overloaded Constructor
    * Calls overloaded BaseNode constructor
  * Copy Constructor
    * Calls BaseNode copy constructor
  * Accessors
  * Mutators
  * getArabic
    * Overridden virtual function from BaseNode class (the function is an accessor in BaseNode class)
    * Returns the Arabic value of the numeral


**LinkedList:**
* Attributes:
  * Head Pointer
  * Tail pointer
* Methods:
  * Default Constructor
  * Overloaded Constructor
    * Takes node and assigns head to point at the node passed in
  * Destructor
    * Recursively deletes linked list
  * Accessor
  * Mutator
  * Print
    * Recursively writes linked list to file
  * Overloaded += operator
    * Usage: list += node
    * Inserts node at the end of the list
  * Overloaded -- operator
    * Usage: list-- or --list
    * Prefix notation (--list): deletes first node in list
    * Postfix notation (list--): deletes last node in list
