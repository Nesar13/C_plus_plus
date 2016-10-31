/* "I pledge my honor that I have abided by the Stevens Honor System."
Author: Nesar Ahmed
Date: 4/06/16
*/


#include <iostream>
#include <algorithm>
#include "MyString.h"

String::String() {
	arr = new char[1];
	arr[0] = '\0';
	len = 0;
}


String::String(const char *s) {
	len = strlen(s);
	arr = new char[len + 1];
	std::copy(s, s + len + 1, arr);
}


String::String(const String &obj) {
	len = obj.len;
	arr = new char[len + 1];
	std::copy(obj.arr, obj.arr + len + 1, arr);
}


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


String::String(String &&obj) {
	len = obj.len;
	arr = obj.arr;
	obj.arr = nullptr;
}


String::~String() {
	if (arr != nullptr)
		delete[] arr;
}


String &String::operator=(const String &rhs) {
	delete[] arr;
	len = rhs.len;
	arr = new char[len + 1];
	std::copy(rhs.arr, rhs.arr + len + 1, arr);
	return *this;
}


String &String::operator=(String &&rhs) {
	delete[] arr;
	len = rhs.len;
	arr = rhs.arr;
	rhs.arr = nullptr;
	return *this;
}



char &String::operator[](int index) {
	// check whether the index is within bounds
	if (index > len || index < 0)
		throw std::out_of_range("Index out of range");
	return arr[index];
}


char String::operator[](int index) const {
	// check whether the index is within bounds
	if (index > len || index < 0)
		throw std::out_of_range("Index out of range");
	return arr[index];
}


int String::length() const {
	return len;
}

bool operator==(const String &lhs, const String &rhs) {
	return strcmp(lhs.arr, rhs.arr) == 0;
}

bool operator<(const String &lhs, const String &rhs) {
	return strcmp(lhs.arr, rhs.arr) < 0;
}


bool operator>(const String &lhs, const String &rhs) {
	return rhs < lhs;
}


bool operator<=(const String &lhs, const String &rhs) {
	return !(rhs < lhs);
}


bool operator>=(const String &lhs, const String &rhs) {
	return !(lhs  < rhs);
}


bool operator!=(const String &lhs, const String &rhs) {
	return !(lhs == rhs);
}


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


const char* String::c_str() const {
	return arr;
}


std::ostream& operator<<(std::ostream &out, const String &obj) {
	return out << obj.c_str();
}
