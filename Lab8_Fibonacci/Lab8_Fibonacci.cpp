/*"I pledge my honor that I have abided by the Stevens Honor System."
Author: Nesar Ahmed
Date: 3/23/16
*/

#include <iostream>
using namespace std; 

int fibonacci(int term);
int term;

int fibonacci(int term) {


	if (term == 0 || term == 1)
		return term;
	else 
		return fibonacci(term - 2) + fibonacci(term - 1);
}


void main() {
	cout << "Enter a term in the sequence: ";
	cin >> term;
	if (term < 0) {

		cout << "Term cannot be negative.";

		throw std::invalid_argument("Received negative value");
	}
	cout << fibonacci(term) << endl;

} 


/*Develop the following function :

int fibonacci(int term);

The function should produce the Fibonacci number at sequence position term by using recursion.Do not write any loops for this code or you will receive no credit.

Also develop a main function that prompts the user for a term number, passes this number to the fibonacci function, and displays the output.

For example :
fibonacci(0) = > 0
fibonacci(2) = > 1
fibonacci(3) = > 2
fibonacci(9) = > 34
fibonacci(-50) = > throw an exception*/