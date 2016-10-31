#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double decimal;
	cout << "Enter a value: ";
	cin >> decimal;
	cout << "Integer value: " << static_cast <int> (decimal) << endl;

	int new_integer = static_cast <int> (decimal);

	cout << "Integer value and the new variable: " << "new_integer= " << new_integer << endl;
	cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
	cout << "Integer with 2 decimal precision: " << static_cast <double> (new_integer) << endl;
	cout << "Integer is odd (1) or even (0): " << new_integer % 2 << endl;
	cout << "I pledge my honor that I have abided by the Stevens Honor System." << endl;
	cout << "Name: Nesar Ahmed \n";

	return 0;
}

/*x = 3;
y = ++x;
// x contains 4, y contains 4 

x = 3;
y = x++;
// x contains 4, y contains 3
In Example 1, the value assigned to y is the value of x after being increased. 
While in Example 2, it is the value x had before being increased.

/*Write a program that does the following :

1. Ask the user to input a number, which may or may not have a decimal component and stores
that number in a type of variable that supports decimal numbers.
2. Print out the integer portion of the number without storing the number in a second variable.
3. Store the number in an actual integer variable, taking care to do so without getting any warnings or errors from the compiler.
4. Print out the new integer variable.
5. Print the number with exactly two decimal places shown.
6. Using the integer number, display a 0 if it is even or a 1 if it is odd.
You can accomplish this without conditional statements.
7. Display your name to the screen. */
