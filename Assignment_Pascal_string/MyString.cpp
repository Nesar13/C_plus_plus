/* "I pledge my honor that I have abided by the Stevens Honor System." 
Author: Nesar Ahmed
Date: 4/13/16
*/

#include <iostream>
#include <algorithm>
#include "MyString.h"

char temp[255];  // used in c_str
char lharr[255]; // used in compares
char rharr[255]; // used in compares

				 // Default constructor
String::String() {
	arr = new char[1];
	arr[0] = '\0';
	len = 0;
}

// Constructor. Converts a C-string to a String object
String::String(const char *s) {
	len = strlen(s);
	arr = new char[len + 1];
	arr[0] = len;
	for (int i = 1; i < len + 1; i++)
	{
		arr[i] = s[i - 1];
	}
	//	len =  strlen(s);
	//	arr = new char[len + 1];
	//	std::copy(s, s + len + 1, arr);
}

// Copy constructor.
String::String(const String &obj) {
	len = obj.len;
	arr = new char[len + 1];
	std::copy(obj.arr, obj.arr + len + 1, arr);
}

// Pascal String Constructor
String::String(const char *str, bool pascal) {
	if (pascal) {
		len = strlen(str);
		arr = new char[len + 1];
		arr[0] = len;
		for (int i = 1; i < len + 1; i++)
		{
			arr[i] = str[i - 1];
		}
	}
	else {
		len = strlen(str);
		arr = new char[len + 1];
		std::copy(str, str + len + 1, arr);
	}
}

// Move constructor.
String::String(String &&obj) {
	len = obj.len;
	arr = obj.arr;
	obj.arr = nullptr;
}

// Destructor
String::~String() {
	if (arr != nullptr)
		delete[] arr;
}

// Assignment operator
String &String::operator=(const String &rhs) {
	delete[] arr;
	len = rhs.len;
	arr = new char[len + 1];
	std::copy(rhs.arr, rhs.arr + len + 1, arr);
	return *this;
}

// Move assignment operator
String &String::operator=(String &&rhs) {
	delete[] arr;
	len = rhs.len;
	arr = rhs.arr;
	rhs.arr = nullptr;
	return *this;
}


// Mutator operator[]
char &String::operator[](int index) {
	// check whether the index is within bounds
	if (index > len || index < 0)
		throw std::out_of_range("Index out of range");
	return arr[index];
}

// Accessor operator[]
char String::operator[](int index) const {
	// check whether the index is within bounds
	if (index > len || index < 0)
		throw std::out_of_range("Index out of range");
	return arr[index];
}

// Get the length (number of characters) of a String object
int String::length() const {
	return len;
}

bool operator==(const String &lhs, const String &rhs) {
	// return strcmp(lhs.arr, rhs.arr) == 0;
	lhs.setlharr();
	rhs.setrharr();
	return strcmp(lharr, rharr) == 0;
}

bool operator<(const String &lhs, const String &rhs) {
	lhs.setlharr();
	rhs.setrharr();
	return strcmp(lharr, rharr) < 0;
}

// Friend functions for > comparison
bool operator>(const String &lhs, const String &rhs) {
	return rhs < lhs;
}

// Friend functions for <= comparison
bool operator<=(const String &lhs, const String &rhs) {
	return !(rhs < lhs);
}

// Friend functions for >= comparison
bool operator>=(const String &lhs, const String &rhs) {
	return !(lhs  < rhs);
}

// Friend functions for != comparison
bool operator!=(const String &lhs, const String &rhs) {
	return !(lhs == rhs);
}

//	Friend function for string concatination
String operator+(const String &lhs, const String &rhs) {
	int strLength = lhs.len + rhs.len + 1;
	char *tmpStr = new char[strLength];
	for (auto i = 0; i < lhs.len; ++i)
		tmpStr[i] = lhs.arr[i];
	for (auto i = 0; i <= rhs.len; ++i)
		tmpStr[lhs.len + i] = rhs.arr[i];
	String retStr(tmpStr);
	delete[] tmpStr;
	return retStr;
}

// Return C style character string
const char* String::c_str() const {

	int i;
	for (i = 1; i < arr[0] + 1; i++) {
		temp[i - 1] = arr[i];
	}
	temp[i] = '\0';

	return temp;
}

// set left compare to C style character string
const char* String::setlharr() const {

	int i;
	for (i = 1; i < arr[0] + 1; i++) {
		lharr[i - 1] = arr[i];
	}
	lharr[i] = '\0';

	return lharr;
}
// set right compare C style character string
const char* String::setrharr() const {

	int i;
	for (i = 1; i < arr[0] + 1; i++) {
		rharr[i - 1] = arr[i];
	}
	rharr[i] = '\0';

	return rharr;
}

//	Friend function for output
std::ostream& operator<<(std::ostream &out, const String &obj) {
	return out << obj.c_str();
}
/*Modify the provided String class to internally store Pascal strings, which are character arrays that start with a number of characters in the string, followed by those characters, with NO terminating null character. That is:

str should contain a Pascal string.
The constructor created in your Pascal string lab should be included. The normal C-string constructor should also be included, and must convert to Pascal string.
The c_str function must convert back to a C string to provide a C string to the user. It is okay to allocate the memory for the string in this function.
All other functions must perform correctly given the change to the internal string format.
You may NOT store a C string internally along with the Pascal string.*/