/* I pledge my honor that I have abided by the Stevens Honor System."
Nesar Ahmed
*/

#include <iostream>
#include <vector>
using namespace std;


template <typename T, typename C>
class MyIterator
{
private:
	T iterator;
	C container;
public:
	MyIterator(T index, C &container)
	{
		this->iterator = index;
		this->container = container;
	}
	T operator*()
	{
		return container[this->iterator];
	}


	MyIterator& operator++() {
		iterator++;
		return *this;
	}

	MyIterator& operator++(int) {
		iterator++;
		return *this;
	}
	MyIterator& operator--() {
		iterator--;
		return *this;
	}

	MyIterator& operator--(int) {
		iterator--;
		return *this;
	}
	bool operator==(const MyIterator &x)
	{
		return this->iterator == x.iterator;
	}

	bool operator!=(const MyIterator &x)
	{
		return this->iterator != x.iterator;
	}

};



int main()
{
	vector<int> vect = { 10,20,30,40,50,60,70,80,90 };
	int x = vect.size();
	MyIterator < int, vector<int>  > iter(0, vect);

	cout << "Random-access sequence container : ";
	for (auto iter = MyIterator < int, vector<int> >(0, vect); iter != MyIterator < int, vector<int> >(x, vect); iter++)
		cout << *iter << " ";

	cout << endl;
	cout << "Initializaion : vect[0] = " << *iter << endl;
	// for ++ operator;
	iter++;//postfix
	cout << "After iter++ : " << *iter << endl;
	++iter;//prefix
	cout << "After ++iter : " << *iter << endl;
	//for -- operator;
	iter--;//postfix
	cout << "After iter-- : " << *iter << endl;
	--iter;//prefix
	cout << "After --iter : " << *iter << endl;

	cout << "Use != operator in loop " << endl;
	//for != opareator
	for (auto iter = MyIterator < int, vector<int> >(0, vect); iter != MyIterator < int, vector<int> >(x, vect); iter++)
	{

		cout << *iter << endl;
		if
			//for == operator
			(iter == MyIterator < int, vector<int>  >(2, vect))
		{
			cout << "Test for == operator when iter = 2 " << endl;
		}

	}

	return 0;
}

/*Create an iterator class that, using templates, can operate on 
any random - access sequence container.Random - access containers are containers that can be accessed using the[] operator. 
An example of such a container is vector.An example iterator type would be MyIterator<vector<int>>.

The class must have a single constructor, that takes a reference to a container and an index to start the iterator.

This class must support operator overloads for :

	*-go to the actual item referenced by the iterator
	++ - move the iterator forward to the next item
	-- - move the iterator backward to the previous item
	== -check to see if the current iterator is at the same position in same the random - access sequence container as another
	!= -check to see that the current iterator is at a different position or a different sequence container */