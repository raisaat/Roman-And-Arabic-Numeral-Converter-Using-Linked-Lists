#include "BaseNode.h"
using namespace std;

// This function converts an arabic numeral to its roman equivalent
string convertToRoman(int num)
{
	int thousands, hundreds, tens, ones;

	thousands = num / 1000;
	hundreds = (num % 1000) / 100;
	tens = ((num % 1000) % 100) / 10;
	ones = ((num % 1000) % 100) % 10;

	// Create a string object and assign the empty string to it
	string r = "";

	// Convert the arabic numeral to its roman equivalent
	if (thousands > 0 && thousands <= 4)
	{
		for (int index = 0; index < thousands; index++)
			r += "M";
	}

	if (hundreds > 0 && hundreds < 4)
	{
		for (int index = 0; index < hundreds; index++)
			r += "C";
	}

	else if (hundreds == 4)
		r += "CD";

	else if (hundreds >= 5 && hundreds < 9)
	{
		r += "D";

		for (int index = 5; index < hundreds; index++)
			r += "C";
	}

	else if (hundreds == 9)
		r += "CM";

	if (tens > 0 && tens < 4)
	{
		for (int index = 0; index < tens; index++)
			r += "X";
	}

	else if (tens == 4)
		r += "XL";

	else if (tens >= 5 && tens < 9)
	{
		r += "L";

		for (int index = 5; index < tens; index++)
			r += "X";
	}

	else if (tens == 9)
		r += "XC";

	if (ones > 0 && ones < 4)
	{
		for (int index = 0; index < ones; index++)
			r += "I";
	}

	else if (ones == 4)
		r += "IV";

	else if (ones >= 5 && ones < 9)
	{
		r += "V";

		for (int index = 5; index < ones; index++)
			r += "I";
	}

	else if (ones == 9)
		r += "IX";

	// Return r
	return r;
}

// This function converts a roman numeral to its arabic equivalent
int convertToArabic(string str)
{
	// Create an int variable and assign 0 to it
	int a = 0;
	
	// convert the roman numeral to its arabic equivalent
	for (int count = 0; count < str.length(); count++)
	{
		if (str[count] == 'M')
			a += 1000;
		else if (str[count] == 'D')
			a += 500;
		else if (str[count] == 'C' && (str[count + 1] == 'M' || str[count + 1] == 'D'))
			a -= 100;
		else if (str[count] == 'C')
			a += 100;
		else if (str[count] == 'L')
			a += 50;
		else if (str[count] == 'X' && (str[count + 1] == 'L' || str[count + 1] == 'C'))
			a -= 10;
		else if (str[count] == 'X')
			a += 10;
		else if (str[count] == 'V')
			a += 5;
		else if (str[count] == 'I' && (str[count + 1] == 'V' || str[count + 1] == 'X'))
			a -= 1;
		else if (str[count] == 'I')
			a += 1;
	}

	// Return a
	return a;
}

// Overloaded string insertion operator function
ostream& operator<< (ostream &strm, const BaseNode &obj)
{
	// Write the arabic and roman numerals of the BaseNode object passed in to the ostream object
	strm << left << setw(15) << obj.roman << ' ' << setw(4) << obj.arabic << endl;

	// Return the ostream object
	return strm;
}

// Overloaded string extraction operator
istream& operator>> (istream &strm, BaseNode &obj)
{
	string str;	// To hold data read in from the istream object

	// Read the data from the istream object into str
	strm >> str;

	// If the first character of the string is a digit
	if (str[0] >= 48 && str[0] <= 57)
	{
		// Check if all the characters in the string are digits
		for (int count = 1; count < str.length(); count++)
		{
			// If a non-digit character is found, return
			if (str[count] < 48 || str[count] > 57)
				return strm;
		}

		// Convert the string of digits into an int. If it
		// is not between 1 and 4999, return
		if (atoi(str.c_str()) < 1 || atoi(str.c_str()) > 4999)
			return strm;
		
		// Convert the string to an int and assign it to the arabic member variable of the object
		obj.arabic = atoi(str.c_str());

		// Convert the arabic numeral to its roman equivalent and assign it to the roman member variable of the object
		obj.roman = convertToRoman(obj.arabic);
	}

	// Else if the first character of the string is a valid roman digit
	else if (str[0] == 'I' || str[0] == 'V' || str[0] == 'X' || str[0] == 'L' || str[0] == 'C' || str[0] == 'D' || str[0] == 'M')
	{
		// Check if all the characters in the string are valid roman digits
		for (int count = 1; count < str.length(); count++)
		{
			// If an invalid character is found, return
			if (str[count] != 'I' && str[count] != 'V' && str[count] != 'X' && str[count] != 'L' && str[count] != 'C' && str[count] != 'D' && str[count] != 'M')
				return strm;
		}

		// Assign the string to the roman member variable of the object
		obj.roman = str;

		// Convert the roman numeral to its arabic equivalent and assign it the arabic member variable of the object
		obj.arabic = convertToArabic(str);
	}

	// Return the istream object
	return strm;
}