#include <string>
#include <ostream>
#include <istream>
#include <iomanip>
using namespace std;

#ifndef BaseNode_H
#define BaseNode_H

// Forward declaration
class BaseNode;

// Prototypes of friend functions
ostream& operator<< (ostream &strm, const BaseNode &obj);
istream& operator>> (istream &strm, BaseNode &obj);
string convertToRoman(int);
int convertToArabic(string);

class BaseNode
{
protected:
	string roman;	// To hold the roman numeral
	int arabic;		// To hold the arabic numeral

public:
	// Default constructor
	BaseNode() { roman = ""; arabic = 0; }

	// Overloaded constructor
	BaseNode(string r, int a) { roman = r; arabic = a; }

	// Copy constructor
	BaseNode(const BaseNode &obj)
	{
		// Assign the roman and arabic variables to the
		// roman and arabic numerals of the object passed in
		roman = obj.roman;
		arabic = obj.arabic;
	}

	// Mutators
	void setArabic(int num)
	{
		arabic = num;
		roman = convertToRoman(num); // Convert the arabic numeral to its roman equivalent
	}

	void setRoman(string str)
	{
		roman = str;
		arabic = convertToArabic(str); // Convert the roman numeral to its arabic equivalent
	}

	// Accessor to access the roman numeral
	string getRoman() const { return roman; }

	// Pure virtual function
	virtual int getArabic() const = 0;

	// Friends to the class
	friend ostream& operator<< (ostream &strm, const BaseNode &obj);
	friend istream& operator>>(istream &strm, BaseNode &obj);
	friend string convertToRoman(int);
	friend int convertToArabic(string);
};
#endif