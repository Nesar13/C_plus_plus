//"I pledge my honor that I have abided by the Stevens Honor System."
// Nesar Ahmed
// 16 February 2016

#include<iostream>
#include<vector>

using namespace std; 


/*vector <int> vect{ 5,4,3,2,1 }; 

int binarySearch(vector<int> vect, int);

int tarVal;
int main()
{
	cout << "The integers are: ";
	for (auto i = 0; i < 5; i++)
		cout << vect[i] << " ";

	cout << endl <<  "Target value: ";
	cin >> tarVal;
	cout << "Is this number in the vector : ";
	if (binarySearch(vect, tarVal) == 1)
		cout << "True" << endl; 
	else cout << "False" << endl;
	
	
	
	
	return 0; 
}
int binarySearch(vector<int>  vect, int tarVal)
{
	int first = 0, last = vect.size() - 1, mid; 
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (tarVal > vect[mid])
			last = mid - 1;
		else if (tarVal < vect[mid])
			first = mid + 1;
		else return true;
	}
	return false;
} 

/*Suppose a one - dimensional vector vect containing integers is 
arranged in descending order.Write a user - defined function in C++ to search 
for an integer from vect with the help of binary search.The first function should 
return a bool false to show absence of the number and bool true to show presence 
of the number in the vector.The function you create should have 
two parameters : (i)vector vect(ii) the number to be searched.*/


// function declaration for sequential search 
int sequentialSearch(vector<int> const &A, int targetVal);

void main()
{
	vector<int> myVector
	{ 2309, 4498, 3184, 9963, 4190, 6512, 2106, 3302, 1681, 7140 };
	cout << "The " << myVector.size() << " vector elements are:" << endl; 
	for (int i = 0; i < myVector.size(); i++)
		cout << myVector[i] << " ";
	cout << endl << "Enter target value : ";
	int tarVal;
	cin >> tarVal;
	int index = sequentialSearch(myVector, tarVal);
	if (index >= 0)
		cout << "Target value = " << tarVal
		<< " found at vector index = " << index << endl;
	else
		cout << "Target value = " << tarVal << " not found" << endl;

} // end main function

int sequentialSearch(vector<int> const &A, int targetVal)
{// searches A[0] ... A[A.size()-1] for targetVal.
// returns index where found, or -1 if not found.
for (int index = 0; index < A.size(); index++)
{
	if (targetVal == A[index])
		return index;
} // end for
return -1;
} // end function sequentialSearch