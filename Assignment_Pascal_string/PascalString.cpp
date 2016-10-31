#include<iostream>
#include "MyString.h"

using namespace std;


int main()
{
	String mystring("Hi There.");
	cout << mystring.c_str() << "\n";
	String copiedString(mystring);
	cout << copiedString.c_str() << "\n";
	if (mystring == copiedString) {
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No." << "\n";
	}
	String stringA("A");
	String stringB("B");
	if (stringA < stringB) {
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No." << "\n";
	}
	return 0;
}