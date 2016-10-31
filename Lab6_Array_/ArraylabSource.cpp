/*"I pledge my honor that I have abided by the Stevens Honor System."
By: Nesar Ahmed
8 February 2015 */

#include <iostream>
#include <array>
using namespace std; 

int myArray[5] = { 1,2,3,4,5 };

class my_int_array {
private: 
	int *ptr;
public: 
	int size() { return sizeof(my_int_array); } //returns the length of the array
	int at(int which) { return myArray[which]; } //returns the array element at that index, or displays
				  // an error if index out of bounds
	my_int_array(); //contructor
	my_int_array(const my_int_array &obj); //copy constructor
	my_int_array(int i);
	
};

 

my_int_array::my_int_array() { //contructor takes an existing array and size

	myArray[5];
}

my_int_array::my_int_array(const my_int_array &obj) {
	ptr = myArray; 
	*ptr = *obj.ptr; //copies value of myArray


}

my_int_array::my_int_array(int i) { //takes size and makes an empty array of that size

	cout << "Enter a size for a constructor: " << endl; 
	cin >> i; 
	myArray[i] = { 0 };


}


int main() {
	my_int_array arr(5);
	my_int_array an_array;
	cout << an_array.size() << "\n";
	cout << an_array.at(2) << " \n";
	
	return 0;
}