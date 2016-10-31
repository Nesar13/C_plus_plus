/* I pledge my honor that I have abide by the Stevens Honor System. " 
Nesar Ahmed
*/

#include <iostream>
#include <vector>
#include <algorithm>
//couldn't figure out how to get amount of numbers to be generated
using namespace std;
int n;


vector<int> initSTL() {
	vector<int> v(n);
	generate(v.begin(), v.end(), []() 
	{ return rand() % 100; });
	return v;
}

int main() {
	int n;
	cout << " How many numbers do you want to read in?: " << endl; 
	cin >> n;

	cout << initSTL << endl;
	
	return 0; 

}