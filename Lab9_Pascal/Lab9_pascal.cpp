#include<iostream>
#include "MyString.h"

using namespace std;

int main()
{
	cout << String("For test", true) << "\n";
	

	return 0;
}


/*Modify the existing C++ MyString.h to include an additional constructor:

String(const char *str, bool pascal)

When pascal is false, str should be treated as a standard C-string. 
However, when pascal is true, interpret str as a "Pascal" string. 
Pascal strings are length-prefixed. 
That is, the first byte is the length of the string, and the remaining bytes (if any) are the characters.
There is no null-terminating byte.
Construct your new string class from a Pascal string when provided with one. 
All other behavior should be the same.*/